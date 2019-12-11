# GolangNote
Go并发编程
# 语言特性
 - 开放源代码
 - 静态类型和编译型：在Go中，每个变量或常量都必须在声明时指定类型，且不可改变。
 - 跨平台
 - 自动垃圾回收
 - 原生的并发编程
 - 完善的构建工具
 - 多编程范式

# 标准命令
 - build：用于编译指定的代码包或Go程序源码文件。
 - clean：用于清除因执行其他go命令而遗留下来的临时目录和文件
 - doc：用于显示Go语言代码包以及程序实体的文档
 - env：查看环境信息
 - get：下载
 - install：安装
 - run：不生成执行文件，直接运行源码文件
 - version：版本

# 基本构成要素
 Go语言符号（词法元素）：
 - 标识符（identifier）
   - 预定义标识符，主要包括
	   - 所有基本数据类型的名称
	   - 接口类型error
	   - 常量true，false和iota
   - 所有内建函数名称：append、cap、close、complex、copy、delete、imag、len、make、new、panic、print、println、real和recover。
 - 关键字（keyword）

 | 类型 | 关键字 |
 | :---: | :---: |
 | 程序声明| import和package |
 | 程序实体声明和定义 | chan、const、func、interface、map、struct、type和var |
 | 程序流程控制 | go、select、break、case、continue、default、defer、else、fallthrough、for、goto、if、range、return和switch |

 - 字面量（literal）
 - 分隔符（delimiter）
 - 操作符（operator）
	 - 二元操作符优先级（数字越大优先级越高）
	
 | 优先级 | 操作符 |
 | :---: | :---: |
 | 5 | *、/、%、<<、>>、&和&^ |
 | 4 | +、-、&#124; 和^ |
 | 3 | ==、!=、<、<=、>和>= |
 | 2 | && |
 | 1 | &#124;&#124; |