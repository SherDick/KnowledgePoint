## gRPC
　　gRPC是一个高性能、开源和通用的RPC框架，面向移动和HTTP/2设计。
　　在 gRPC 里*客户端*应用可以像调用本地对象一样直接调用另一台不同的机器上*服务端*应用的方法，使得您能够更容易地创建分布式应用和服务。与许多 RPC 系统类似，gRPC 也是基于以下理念：定义一个*服务*，指定其能够被远程调用的方法（包含参数和返回类型）。在服务端实现这个接口，并运行一个 gRPC 服务器来处理客户端调用。在客户端拥有一个*存根*能够像服务端一样的方法。

[picture error](https://github.com/SherDick/KnowledgePoint/blob/master/OSS.md)

[gRPC官方文档](https://doc.oschina.net/grpc?t=60133)

