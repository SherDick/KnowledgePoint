package main

import "fmt"

type Singletoner interface {
	TODO()
}

type singleton struct {
}

var instance Singletoner

func init() {
	instance = new(singleton)
}

func GetInstance() Singletoner {
	if nil != instance {
		return instance
	}
	return nil
}

func (singleton) TODO() {
	fmt.Printf("TODO:...\n")
}

func main() {
	s1 := GetInstance()
	fmt.Printf("s1:%p, instance:%p\n", s1, instance)

	s2 := GetInstance()
	fmt.Printf("s2:%p, instance:%p\n", s2, instance)

}
