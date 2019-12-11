> Redis是一个开源的使用ANSI C语言编写、支持网络、可基于内存亦可持久化的日志型、Key-Value数据库，并提供多种语言的API。
# 定义
	Redis是一个Key-Value存储系统，和Memcached类似，它支持存储的value类型相对更多，包括string（字符串）、list（链表）、set（集合）、
	zset（sorted set--有序集合）和hash（哈希类型）。这些数据类型都支持push/pop、add/remove及取交集并集和差集及更丰富的操作，并且这
	些操作均为原子性的。支持各种不同方式的排序，会周期性的把更新的数据写入磁盘或把修改操作写入追加的记录文件，并在此基础上实现了
	master-slave（主从）同步。	
	使用内存存储（in-memory）的非关系数据库，每种数据存储类型都有自己的专属命令，另外还有批量操作（bulk operation）和不完全（partial）的事务支持。
# 常用命令
	TYPE key：获取key的类型
	KEYS pattern：匹配所有符合模式的key
	LPUSH key string：将某个值加入到一个key列表头部
	RPUSH key string：将某个值加入到一个key列表尾部
	LLEN key：列表长度
	LRANGE key start end：返回列表中某个范围的值
	LINDEX key index：获取列表中特定索引号的值，复杂度为O(N)
	LSET key index value：设置列表中某个位置的值

# 数据结构
	提供五种数据类型：string，hash，list，set及zset（sorted set）
	STRING：可以是字符串、整数或浮点数
	LIST：一个链表，链表上的每个节点都包含了一个字符串，从链表的两端push或者pop元素
	SET：包括字符串的无序收集器（unordered collection），并且被包含的每个字符串都是独一无二、各不相同的
	HASH：包括键值对的无序散列表
	ZSET（有序集合）：字符串成员（member）与浮点数分值（score）之间的有序映射，元素的排序顺序由分值的大小决定
# 存储
	redis使用两种文件格式：全量数据和增量请求。
	·全量数据格式：把内存中的数据写入磁盘，便于下次读取文件进行加载；
	·增量请求文件：把内存中的数据序列化为操作请求，用于读取文件进行replay得到数据，序列化的操作包括SET、RPUSH、
	SADD、ZADD。
	redis的存储分为内存存储、磁盘存储和log文件三部分，配置文件中有三个参数对其进行配置。