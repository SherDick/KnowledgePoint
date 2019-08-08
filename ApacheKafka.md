## Apache Kafka(分布式流处理平台)
　　Kafka作为一个集群，运行在一台或多台服务器上
  
　　Kafka通过Topic对存储的流数据进行分类
  
　　每条记录中包含一个key，一个value和一个timestamp（时间戳）

四个核心的API：
- The Producer API：允许一个应用程序发布一串流式的数据到一个或多个Kafka topic
- The Consumer API：允许一个应用程序订阅一个或多个 topic ，并且对发布给他们的流式数据进行处理。
- The Streams API：允许一个应用程序作为一个流处理器，消费一个或者多个topic产生的输入流，然后生产一个输出流到一个或多个topic中去，在输入输出流中进行有效的转换。
- The Connector API：允许构建并运行可重用的生产者或者消费者，将Kafka topics连接到已存在的应用程序或者数据系统。比如，连接到一个关系型数据库，捕捉表（table）的所有变更内容。
![error](https://github.com/SherDick/KnowledgePoint/raw/master/Pictures/kafka-apis.png)


三种特性：
- 可以发布/订阅流式的记录
- 可以存储流式的记录，并有较好的容错性
- 可以在流式记录产生时就进行处理

## Topic和日志
### 流式的记录-topic
　　Topic即为数据主题，是数据记录发布的地方，可以用来区分业务系统。Kafka中的Topics总是多订阅者模式，一个topic可以拥有一个或者多个消费者来订阅它的数据。
　　对于每一个topic， Kafka集群都会维持一个分区日志，如下所示：
![error](https://github.com/SherDick/KnowledgePoint/raw/master/Pictures/log_anatomy.png)


　　每个分区都是有序且顺序不可变的记录集，并且不断地追加到结构化的commit log文件。分区中的每一个记录都会分配一个id号来表示顺序，我们称之为offset，offset用来唯一的标识分区中每一条记录。
  
　　Kafka 集群保留所有发布的记录—无论他们是否已被消费—并通过一个可配置的参数——保留期限来控制. 举个例子， 如果保留策略设置为2天，一条记录发布后两天内，可以随时被消费，两天过后这条记录会被抛弃并释放磁盘空间。Kafka的性能和数据大小无关，所以长时间存储数据没有什么问题。
![error](https://github.com/SherDick/KnowledgePoint/raw/master/Pictures/log_consumer.png)

　　在每一个消费者中唯一保存的元数据是offset（偏移量）即消费在log中的位置.偏移量由消费者所控制:通常在读取记录后，消费者会以线性的方式增加偏移量，但是实际上，由于这个位置由消费者控制，所以消费者可以采用任何顺序来消费记录。例如，一个消费者可以重置到一个旧的偏移量，从而重新处理过去的数据；也可以跳过最近的记录，从"现在"开始消费。
  
#### 日志中的partition（分区）用途
- 当日志大小超过了单台服务器的限制，允许日志进行扩展。每个单独的分区都必须受限于主机的文件限制，不过一个主题可能有多个分区，因此可以处理无限量的数据。
- 可以作为并行的单元集


#### [Kafka文档](http://kafka.apache.org)
