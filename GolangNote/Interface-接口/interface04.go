package main

import (
	"fmt"
)

type EmptyInterface interface {
}

func printArray(arr interface{}) {
	v, ok := arr.([]int)
	if ok {
		for _, i := range v {
			fmt.Print(i, " ")
		}
		fmt.Println()
	}
}

func main() {
	arr := []int{1, 2, 3, 4}
	printArray(arr)
}
