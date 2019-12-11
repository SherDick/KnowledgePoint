/*
Go 语言中同时有函数和方法。一个方法就是一个包含了接受者的函数，接受者可以是命名类型或者结构体类型的一个值或者
	是一个指针。所有给定类型的方法属于该类型的方法集。语法格式如下：
func (variable_name variable_data_type) function_name() [return_type]{
   //TODO:
}
*/
package main

import (
	"fmt"
)

var PI float64 = 3.1415926

type Circle struct {
	redius float64
}

//方法（c为值接收者，即副本）
func (c Circle) getArea() float64 {
	return PI * c.redius
}

type CirclePoint struct {
	redius float64
}

//指针方法（c为指针接收者，即引用）
func (c *CirclePoint) getArea() float64 {
	return PI * c.redius
}

func main() {
	c1 := Circle{redius: 100}
	fmt.Printf("area = %.2f\n", c1.getArea())
	c2 := new(CirclePoint)
	c2.redius = 100
	fmt.Printf("point area = %.2f\n", c2.getArea())
}
