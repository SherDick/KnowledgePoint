# 形式一
```golang
// 如同 C 的 for 循环
for init; condition; post { }
```
# 形式二
```golang
// 如同 C 的 while 循环
for condition { }
```

# 形式三
```golang
// 如同 C 的 for(;;) 循环
for { }
```

# 短声明
```golang
um := 0
for i := 0; i < 10; i++ {
sum += i
}
```