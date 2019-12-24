### mysql数据库索引
- 查看索引
```mysql
show index from salaries;
show keys from salaries; 
```
	- Non_unique：若索引不包含重复词则为0，反之为1
	- Key_name：索引的名称
	- Seq_in_index：索引中的列序列号，从1开始
	- Column_name：列名称
	- Collation：列以什么方式存储在索引中，MYSQL中，有值‘A’（升序）或NULL（无分类）
	- Cardinality：索引中唯一值的数目的估计值。
	- Sub_part：若整列被编入索引，则为空
	- Index_type：索引方法（BTREE，FULLTEXT，HASH，RTREE）

```mysql
select * from sal_index where emp_no=10001;  -- 普通索引 无索引：0.646s  有索引：0.00036s
select * from sal_index where emp_no=10001 and salary=74333; -- 联合索引 无索引：0.642s  有索引：0.00066s
create index emp_no on sal_index(emp_no);
create index no_sal on sal_index(emp_no, salary);
```

### 基本索引类型
- 普通索引（单列索引）
```mysql
create index index_name on table_name(col_name)
alter table table_name add index index_name(col_name)
drop index index_name on table_name
alter table table_name drop index index_name
```
- 复合索引（组合索引）

复合索引遵守“最左前缀”原则。
```mysql
create index index_name on table_name(col_name1, col_name2, ...)
alter table table_name add index table_name(col_name1, col_name2, ...)
```
- 唯一索引

唯一索引限制列的值必须唯一，可以存在空值，有且仅有一条。
```mysql
create unique index index_name on table_name(col_name)
create unique index index_name on table_name(col_name1, col_name2, ...)
alter table table_name add unique index index_name(col_name)
alter table table_name add unique index index_name(col_name1, col_name2, ...)
```
- 主键索引
```mysql
alter table table_name add primary key(col_name) --表中不存在主键时
```
- 全文索引


### explain
- select_type: 表示select语句的类型
- table: 表名
- partitions: 匹配的分区
- type: 访问表的方式

ALL、index、range、ref、eq_ref、const、system、NULL（从左至右，性能由差至好）
- possible_keys: 可能用到的索引
- key: 实际用的索引
- key_len: 索引中使用的字节数
- ref: 列与索引的比较，哪些列或常量被用于查找索引列上的值
- rows: 估算的结果集行数
- filtered: 按条件过滤的行百分比
- extra: 执行情况描述与说明


### 优秀博客
[MySQL索引底层实现原理](https://www.cnblogs.com/boothsun/p/8970952.html)

[基于Mysql数据库亿级数据下的分库分表方案](https://www.cnblogs.com/jpfss/p/10270270.html)

[深入理解MySQL索引原理和实现——为什么索引可以加速查询？](https://blog.csdn.net/tongdanping/article/details/79878302)