package main

import (
	"fmt"
)

var PI float32 = 3.1415926

type Shapeable interface {
	Area() float32
}

type Rect struct {
	Width  float32
	Height float32
}

type Circle struct {
	Radius float32
}

func (r Rect) Area() float32 {
	return r.Width * r.Height
}

func (c Circle) Area() float32 {
	return PI * c.Radius * c.Radius
}

func main() {
	r := Rect{10, 10}
	c := Circle{10}
	shapes := []Shapeable{r, c}
	for s, _ := range shapes {
		fmt.Println(s)
		fmt.Println(shapes[s])
		fmt.Println(shapes[s].Area())
	}
}
