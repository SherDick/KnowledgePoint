package main

import (
	"fmt"
)

type Singletoner interface {
	TODO()
}

type singleton struct {
}

// 全局唯一
var instance Singletoner

func (singleton) TODO() {
	fmt.Printf("TODO:...\n")
}

func GetInstance() Singletoner {
	if nil == instance {
		fmt.Printf("new singleton\n")
		instance = new(singleton)
	}
	return instance
}

func main() {
	s1 := GetInstance()
	fmt.Printf("s1:%p, instance:%p\n", s1, instance)

	s2 := GetInstance()
	fmt.Printf("s2:%p, instance:%p\n", s2, instance)
}
