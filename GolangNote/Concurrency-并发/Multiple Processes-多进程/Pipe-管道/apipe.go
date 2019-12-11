package main

//匿名管道

import (
	"bytes"
	"fmt"
	"os/exec"
)

func runCmdPipe() {
	fmt.Println("Run command 'ps aux | grep apipe': ")
	cmd1 := exec.Command("ps", "aux")     //命令1
	cmd2 := exec.Command("grep", "apipe") //命令2
	var ouputBuf1 bytes.Buffer
	cmd1.Stdout = &ouputBuf1 //将*bytes.Buffer类型赋给Stdout，cmd1的输出内容将被写入ouputBuf1中
	//启动命令
	if err := cmd1.Start(); err != nil {
		fmt.Println("cmd1 start Error: %s\n", err)
		return
	}
	//阻塞等待，直到cmd1运行完毕
	if err := cmd1.Wait(); err != nil {
		fmt.Println("cmd1 wait Error:%s\n", err)
		return
	}
	//将cmd1的输出内容作为cmd2的输入
	cmd2.Stdin = &ouputBuf1
	var ouputBuf2 bytes.Buffer
	//将cmd2的输出内容写入outputBuf2中
	cmd2.Stdout = &ouputBuf2
	if err := cmd2.Start(); err != nil {
		fmt.Println("cmd2 start Error: %s\n", err)
		return
	}
	//阻塞等待，直到cmd2运行完毕
	if err := cmd2.Wait(); err != nil {
		fmt.Println("cmd2 wait Error:%s\n", err)
		return
	}

	fmt.Printf("%s\n", ouputBuf2.Bytes())
}

func main() {

}
