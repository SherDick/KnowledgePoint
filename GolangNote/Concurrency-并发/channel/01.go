package main

import (
	"fmt"
	"sync"
	"time"
)

func channel01(arr []int, c chan int) {
	sum := 0
	for _, num := range arr {
		sum += num
	}
	c <- sum

}

func test01() {
	arr := []int{1, 1, 1, 1, 1, 1, 1, 1, 1}
	c := make(chan int)
	// fmt.Printf("len=%d\n", len(arr))
	go channel01(arr, c)
	go channel01(arr[:len(arr)/2], c)
	go channel01(arr[len(arr)/2:], c)
	sum1, sum2, sum3 := <-c, <-c, <-c
	fmt.Printf("sum1=%d, sum2=%d, sum3=%d\n", sum1, sum2, sum3)
}

func test02(c chan int, w *sync.WaitGroup) {
	arr := []int{1, 2, 3, 4, 5, 6, 7, 8, 9}
	for _, num := range arr {
		c <- num
		if num%3 == 0 {
			time.Sleep(time.Second * 3)
		}
	}
	close(c)
	w.Done()
}

func main() {
	// num := runtime.NumCPU()
	// fmt.Print(num)
	var wait sync.WaitGroup
	wait.Add(2)
	c := make(chan int, 9)
	go test02(c, &wait)
	go func() {
		for {
			data, ok := <-c
			if !ok {
				fmt.Printf("channel empty\n")
				// time.Sleep(time.Second)
				break
			}
			fmt.Printf("%d\n", data)
			time.Sleep(time.Millisecond * 500)
		}
		wait.Done()
	}()
	wait.Wait()

}
