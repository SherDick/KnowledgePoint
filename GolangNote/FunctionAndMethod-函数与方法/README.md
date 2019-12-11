## 函数的定义
```golang
//这是函数的定义
func notify(email string) {
        fmt.Println("Email is %s", email)
}
```
## 方法的定义
### 值接收者，即副本
```golang
//这是方法的定义
func (u user) notify(email string) {
        fmt.Println("Email is %d", email)
}
```
### 指针接收者，即引用
```golang
//这是方法的定义
func (u *user) notify(email string) {
        fmt.Println("Email is %d", email)
}
```

## Go方法定义示例
```golang
type user struct {
        name string
        email string
}

func (u user) notify() {
        fmt.Println("Email is %d", u.email)
}

func (u *user) changeEmail(email string) {
        u.email = email
}

func main() {
	Sher := user{name: "Sher", email: "Sher@oldexample.com"}
	Sher.notify()
	Sher.changeEmail("SherDick@example.com")
	Sher.notify()
}
```
### 测试
	Email is %d Sher@oldexample.com
	Email is %d SherDick@example.com
- Sher即为对象，name和email为属性（C++中为成员变量），notify和changeEmail为方法（C++中为成员函数）