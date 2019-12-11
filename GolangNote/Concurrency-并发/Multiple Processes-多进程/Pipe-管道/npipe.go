package main

//命名管道

import (
	"fmt"
	"os"
	"time"
)

func main() {
	filePipe()
}

func filePipe() {
	//创建独立命名管道
	reader, writer, err := os.Pipe()
	if err != nil {
		fmt.Printf("Create named pipe Error:%s\n", err)
		return
	}

	go func() {
		output := make([]byte, 100)
		n, err := reader.Read(output)
		if err != nil {
			fmt.Printf("Read data Error:%s\n", err)
			return
		}
		fmt.Printf("Read %d byte(s). \n", n)
	}()

	input := make([]byte, 32)
	for i := 1; i <= 32; i++ {
		input[i-1] = byte(i)
	}
	n, err := writer.Write(input)
	if err != nil {
		fmt.Printf("Write data Error:%s\n", err)
		return
	}
	fmt.Printf("Wirte %d byte(s). \n", n)
	time.Sleep(2 * time.Second)
}
