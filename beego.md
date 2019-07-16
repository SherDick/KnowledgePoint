## beego
　　beego 是一个快速开发 Go 应用的 HTTP 框架，他可以用来快速开发 API、Web 及后端服务等各种应用，是一个 RESTful 的框架，主要设计灵感来源于 tornado、sinatra 和 flask 这三个框架，但是结合了 Go 本身的一些特性（interface、struct 嵌入等）而设计的一个框架。
## 框架特性
### 简单化
　　RESTful支持、MVC模型，可以使用bee工具快速开发应用，包括监控代码修改进行热编译、自动化测试代码以及自动化打包部署。
### 智能化
　　支持智能路由、智能监控，可以监控QPS、内存消耗、CPU使用，以及goroutine的运行状况。
### 模块化
　　beego内置强大的模块，包括Session、缓存操作、日志记录、配置解析、性能监控、上下文操作、ORM模块、请求模拟等强大的模块。
### 高性能
　　beego采用了Go原生的http包来处理请求，goroutine的并发效率应付大流量的Web应用和API的应用。

## beego架构
![error](https://github.com/SherDick/KnowledgePoint/raw/master/Pictures/architecture.png)

　　beego 是基于八大独立的模块构建的，是一个高度解耦的框架。例如：你可以使用 cache 模块来做你的缓存逻辑；使用日志模块来记录你的操作信息；使用 config 模块来解析你各种格式的文件。

## beego的执行逻辑
![error](https://github.com/SherDick/KnowledgePoint/raw/master/Pictures/flow.png)

## beego项目结构
M（models 目录）、V（Views 目录）和C（Controllers目录），main.go为入口文件。