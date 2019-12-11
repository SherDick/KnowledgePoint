## goroutine
创建和销毁代价比线程小，且调用独立于线程。
## 相关原理
### 并发
单个CPU同时执行多个任务，短时间内，CPU来回切换任务执行，在时间上重叠（<font color=red>微观顺序执行，宏观同时执行</font>）。
### 并行
多个CPU执行任务，每一个CPU在同一时刻执行各自的任务，互不抢占自己所在的CPU资源，同时进行。
### 进程
一个程序运行时所需要的基本资源单位。
### 线程
线程共享进程的资源。
### 协程
拥有自己的寄存器上下文和栈。能保存上一次调用时的状态。
## 匿名调用函数表达式
```golang
go func(){
	fmt.println("Hello")
}()
```
- 最后一对圆括号代表对函数的调用行为

## goroutine与线程
### goroutine优点
- **内存消耗更少**，通常为2kb，线程为1Mb
- **创建与销毁的开销更小**，线程需要向OS申请资源，销毁资源时归还，goroutine的创建与销毁由go语言在运行时自己管理。
- **切换开销更小（主要区别）**，线程的调用为抢占式，而goroutine的调用是**协同式**的，不会直接地与OS内核打交道。
## goroutine调用
调度器切换时机：
- Channel接收或发送会造成阻塞的消息
- 新goroutine创建时
- 可以造成阻塞的系统调用
- 垃圾回收

### [调度模型——调度器（MPG）](https://github.com/SherDick/GolangNote/blob/master/Concurrency-%E5%B9%B6%E5%8F%91/README.md)
- [ ] Machine（M）
一个M代表一个内核级线程（工作线程）。 
- [ ] Processor（P）
一个P代表一个Go代码片段所必需的资源（上下文环境）
- [ ] Goroutines（G）
一个G代表一个Go代码片段。





