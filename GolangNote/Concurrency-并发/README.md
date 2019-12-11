## Go并发机制
### 线程实现模型
- [ ] [Machine（M）](#M)
一个M代表一个内核级线程（工作线程）。 
- [ ] [Processor（P）](#P)
一个P代表一个Go代码片段所必需的资源（上下文环境）
- [ ] [Goroutines（G）](#G)
一个G代表一个Go代码片段。

![picture error](https://github.com/SherDick/GolangNote/raw/master/Pictures/goroutine01.jpg)

一个Goroutines（G）的执行都需要Machine（M）和Processor（P）的支持。M与P进行关联之后，就形成了一个有效的G运行环境（内核线程+上下文环境）。

每个P含有一个可运行G的队列runqueue，如图上图中灰色的G并没有运行，而是处理ready状态。该队列中的G会依次传递给与本地P关联的M，并获得运行时机。

![picture error](https://github.com/SherDick/GolangNote/raw/master/Pictures/goroutine02.png)

M与KSE（内核调用实体）总是一对一关系，一个M只能代表一个内核线程，Go的运行时系统（runtime system）用M代表一个内核调度实体。

M与P也为一对一关系，P与G则为一对多关系。它们之间的关系会在实际调用的过程中改变。

#### <span id="M">Machine(M)</span>
一个M代表一个内核线程，M的部分结构图如下所示

![Picture Error](https://github.com/SherDick/GolangNote/raw/master/Pictures/machine.png)

- g0：代表一个特殊的goroutine，Go运行时系统在启动之初被创建，用于执行一些运行时任务。
- mstartfn：M的起始函数（编写go函数时携带的那个函数）
- curg：存放当前M正在运行的G指针
- p：指向与当前M相关联的P。
- nextp：用于暂存与当前M有潜在关联的P。
  - M和P的预联：调度器将某个P赋给某个M的nextp字段
- spinning：bool类型，表示该M是否正在寻找可运行的G。

M在创建之初，会被加入全局的M列表（runtime.allm），起始函数和预联的P也会被设置。

#### <span id="P">Processor（P）</span>
P是G能够在M中运行的关键。Go的运行时系统会实时地让P与不同的M建立或断开关联，以使P中的可运行的G能够及时获得运行时机。

在Go程序启动之初，引导程序在初始化时，会对P的最大数量进行设置，默认数与CPU的总核心数相同。

确定P最大数量后，运行时系统根据该数值重整全局的P列表（runtime.allp），该列表包含了当前运行时系统创建的所有P。运行时系统将P中可运行的G全部取出，并放入调度器的可运行G地队列中。

P可能具有状态
- Pidle：当前P未与任何M存在关联。
- Prunning：当前P正在与某个M关联。
- Psyscall：当前P中的运行的G正在进行系统调用。
- Pgcstop：运行时系统需要停止调度。
- Pdead：当前P不再被使用。

![Picture Error](https://github.com/SherDick/GolangNote/raw/master/Pictures/PStatus.png)
#### <span id="G">Goroutine（G）</span>
一个G代表一个goroutine，Go的编译器把go语句变成对内部函数newproc的调用，并把go函数及其参数都作为参数传递给该函数。

每一个G都会由运行时系统根据其实际状况设置不同的状态，
- Gidle：当前G刚被分配，但还未初始化。
- Grunnable：当前G正在可运行队列中等待运行。
- Grunning：当前G正在运行。
- Gsyscall：当前G正在执行某个系统调用。
- Gwaiting：当前G正在阻塞。
- Gdead：当前G正在闲置。
- Gcopystack：当前G的栈正被移动（栈的扩展/收缩）。

![Picture Error](https://github.com/SherDick/GolangNote/raw/master/Pictures/GStatus.png)

### 承载M，P，G元素实例的容器

| 中文名称 | 源码中的名称 | 作用域 | 描述 |
| :---: | :---: | :---: | :---: |
| 全局M列表 | runtime.allm | 运行时系统 | 存放所有M的一个单向链表 |
| 全局P列表 | runtime.allp | 运行时系统 | 存放所有P的一个数组 |
| 全局G列表 | runtime.allgs | 运行时系统 | 存放所有G的一个切片 |
| 调度器的空闲M列表 | runtime.sched.midle | 调度器 | 存放空闲的M的一个单向链表 |
| 调度器的空闲P列表 | runtime.sched.pidle | 调度器 | 存放空闲的P的一个单向链表 |
| 调度器的可运行G队列 | runtime.sched.runqhead | 调度器 | 存放可运行的G的一个队列 |
| 调度器的自由G列表 | runtime.sched.runqtail | 调度器 | 存放自由的G的两个单向链表 |
| P的可运行G队列 | runtime.p.runq | 本地P | 存放当前P中的可运行G的一个队列 |
| P的自由G列表 | runtime.p.gfree | 本地P | 存放当前P中自由G的一个单向链表 |

### 调度器（scheduler）
#### 基本结构

| 字段名称 | 数据类型 | 描述 |
| :---: | :---: | :---: |
| gcwaiting | uint32 | 是否需要因一些任务而停止调度 |
| stopwait | int32 | 需要停止但未停止的P的数量 |
| stopnote | note | 实现与stopwait相关的事件通知机制 |
| sysmonwait | uint32 | 在停止调度期间系统监控任务是否在等待 |
| sysmonnote | note | 用于实现与sysmonwait相关的事件通知机制 |

字段gcwaiting字段停止调度前置1，恢复时置0。当gcwaiting值为1时，当前P状态置为Pgcstop，然后自减stopwait值。