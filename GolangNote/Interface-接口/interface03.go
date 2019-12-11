package main

import (
	"fmt"
)

var PI float32 = 3.1415926

type Shapeable interface {
	Area() float32
	Circumference() float32
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
func (r Rect) Circumference() float32 {
	return 2 * (r.Height + r.Width)
}

func (c Circle) Area() float32 {
	return PI * c.Radius * c.Radius
}
func (c Circle) Circumference() float32 {
	return 2 * PI * c.Radius
}

/*
func showInfo(s Shapeable) {
	fmt.Printf("Area:%.2f   Circum:%.2f\n", s.Area(), s.Circumference())
}
*/

func showInfo(s Shapeable) {
	switch s.(type) {
	case Rect:
		fmt.Printf("Rect Area:%.2f   Circum:%.2f\n", s.Area(), s.Circumference())
	case Circle:
		fmt.Printf("Circle Area:%.2f   Circum:%.2f\n", s.Area(), s.Circumference())
	}
}

func main() {
	r := Rect{10, 20}
	showInfo(r)

	c := Circle{10}
	showInfo(c)
}
