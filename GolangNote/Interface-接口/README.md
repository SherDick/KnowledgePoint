## 描述
- Go语言中没有类和继承的概念，但是接口的存在使得它可以实现很多面向对象的特性。接口定义了一些方法，但不包含实现的代码（类似C++中的纯虚函数）。

## 接口特点
- 可以包含0个或多个方法的签名
- 只定义方法的签名，不包含实现
- 实现接口不需要显式的声明，只需实现相应的方法即可

## 接口的定义
```golang
type Namer interface {
    method1(param_list) return_list
    method2(param_list) return_list
    ...
}
```
- 通常接口的名字最好以er，r，able结尾

## 空接口
空接口类型interface{}不含一个方法签名，所以所有的数据类型都实现了空接口
空接口类型可以用于存储任意数据类型的实例
如果一个函数的参数是空接口类型interface{}，表明可以使用任意类型的数据
如果一个函数返回一个空接口类型，表明函数可以返回任何类型的数据。
interface{}可用于向函数传递任意类型的变量，但对于函数内部，该变量仍然为interface{}类型，而不是传入的实参类型。

## 类型断言
interface{}可用于向函数传递任意类型的变量，但对于函数内部，该变量仍然为interface{}类型，而不是传入的实参类型。
接口类型向普通类型的转换称为**类型断言**（运行期确定）
```golang
func printArray(arr interface{}){
       //arr是空接口,不是数组类型，报错
   　　for _,v:=range arr{
      　　　　fmt.Print(v," ")
      　　}
   　　fmt.Println()
}
```

可通过类型断言将接口类型转换为**切片类型**，在使用类型断言时，最好判断是否断言成功。
断言失败在编译阶段是不报错的，因此，如果不对断言结果进行判断将可能会因断言失败导致运行错误。
```golang
func printArray(arr interface{}) {
	v, ok := arr.([]int)
	if ok {
		for _, i := range v {
			fmt.Print(i, " ")
		}
		fmt.Println()
	}
}
```