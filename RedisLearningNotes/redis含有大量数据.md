### 查找大key

> redis含有大量数据时，需要找到占内存的大key，然后进行删除
>
> [linux sort命令](https://man.linuxde.net/sort)
>
> [linux awk命令](https://man.linuxde.net/awk)

**解决方案**：利用[rdbtools工具](https://github.com/sripathikrishnan/redis-rdb-tools)和redis的持久化文件dump.rdb

```bash
// 用rdbtools工具生产内存报告
sudo rdb -c memory  ${YourRedisPath}/dump.rdb > test.csv

// 使用vim 查看test.csv，得知每列的分割符为","
// 使用linux sort命令进行排序，排序条件：以","号为分隔符，第四列依照数值的大小进行排序
sudo sort -k4nr -t , test.csv > sort.txt

// 可使用 awk 命令进行分割
awk -F ',' '{print substr($3, 0,18)}' sort.txt | head -1000 | sort -k1 | uniq

// 利用redis中的通配符"*"进行删除大key
redis-cli -h 127.0.0.1 -p 6379  keys 'test*' | xargs redis-cli -h 127.0.0.1 -p 6379 del
```

### keys or scan？

> redis含有大量数据时，怎样查找key？使用keys？
>
> [redis keys命令](http://doc.redisfans.com/key/keys.html)
>
> [redis scan命令](http://doc.redisfans.com/key/scan.html)

当有大量数据时，使用keys会导致redis服务器阻塞，命令执行完之前不能进行任何操作。而scan不会阻塞服务器，每一次只返回部分小key。