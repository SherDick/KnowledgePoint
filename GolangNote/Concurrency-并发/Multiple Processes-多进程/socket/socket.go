package main

import (
	"bytes"
	"fmt"
	"io"
	"math"
	"math/rand"
	"net"
	"strconv"
	"strings"
	"sync"
	"time"
)

const (
	SERVER_NETWORK = "tcp"
	SERVER_ADDRESS = "127.0.0.1:8000"
	DELIMITER      = '\t'
)

var wg sync.WaitGroup

func main() {
	wg.Add(2)
	go server()
	time.Sleep(500 * time.Millisecond)
	go client(1)
	wg.Wait()
}

func printLog(who string, n int, format string, args ...interface{}) {
	if !strings.HasSuffix(format, "\n") {
		format += "\n"
	}
	fmt.Printf("%s[%d]:%s", who, n, fmt.Sprintf(format, args...))
}

func printClientLog(n int, format string, args ...interface{}) {
	printLog("Client", n, format, args...)
}

func printServerLog(format string, args ...interface{}) {
	printLog("Server", 0, format, args...)
}

func read(con net.Conn) (string, error) {
	readBytes := make([]byte, 1)
	var buffer bytes.Buffer
	for {
		_, err := con.Read(readBytes)
		if err != nil {
			return "", err
		}
		readBytes := readBytes[0]
		if readBytes == DELIMITER {
			break
		}
		buffer.WriteByte(readBytes)
	}
	return buffer.String(), nil
}

func write(con net.Conn, content string) (int, error) {
	var buffer bytes.Buffer
	buffer.WriteString(content)
	buffer.WriteByte(DELIMITER)
	return con.Write(buffer.Bytes())
}

func server() {
	var listener net.Listener
	listener, err := net.Listen(SERVER_NETWORK, SERVER_ADDRESS)
	if err != nil {
		printServerLog("Listen Error:%s", err)
		return
	}
	defer listener.Close()
	for {
		con, err := listener.Accept()
		if err != nil {
			printServerLog("Accept Error:%s", err)
			continue
		}
		printServerLog("success connect. (remote address:%s)", con.RemoteAddr())
		go handleCon(con)
	}
}

func client(id int) {
	defer wg.Done()
	con, err := net.DialTimeout(SERVER_NETWORK, SERVER_ADDRESS, 2*time.Second)
	if err != nil {
		printClientLog(id, "Dial Error: %s", err)
		return
	}
	defer con.Close()
	printClientLog(id, "Connected to server. (remote address: %s, local address: %s)",
		con.RemoteAddr(), con.LocalAddr())
	time.Sleep(200 * time.Millisecond)
	requestNumber := 5
	con.SetDeadline(time.Now().Add(5 * time.Millisecond))
	for i := 0; i < requestNumber; i++ {
		req := rand.Int31()
		n, err := write(con, fmt.Sprintf("%d", req))
		if err != nil {
			printClientLog(id, "Write Error: %s", err)
			continue
		}
		printClientLog(id, "Sent request (written %d bytes): %d.", n, req)
	}
	for j := 0; j < requestNumber; j++ {
		strResp, err := read(con)
		if err != nil {
			if err == io.EOF {
				printClientLog(id, "The connection is closed by another side.")
			} else {
				printClientLog(id, "Read Error: %s", err)
			}
			break
		}
		printClientLog(id, "Received response: %s.", strResp)
	}
}

func handleCon(con net.Conn) {
	defer func() {
		con.Close()
		wg.Done()
	}()

	for {
		con.SetReadDeadline(time.Now().Add(10 * time.Second))
		strReq, err := read(con)
		if err != nil {
			if err == io.EOF {
				printServerLog("The connection is closed by another side.")
			} else {
				printServerLog("Read Error: %s", err)
			}
			break
		}
		printServerLog("Received request: %s.", strReq)
		intReq, err := strToInt32(strReq)
		if err != nil {
			n, err := write(con, err.Error())
			printServerLog("Sent error message (written %d bytes): %s.", n, err)
			continue
		}
		floatResp := cbrt(intReq)
		respMsg := fmt.Sprintf("The cube root of %d is %f.", intReq, floatResp)
		n, err := write(con, respMsg)
		if err != nil {
			printServerLog("Write Error: %s", err)
		}
		printServerLog("Sent response (written %d bytes): %s.", n, respMsg)
	}
}
func strToInt32(str string) (int32, error) {
	num, err := strconv.ParseInt(str, 10, 0)
	if err != nil {
		return 0, fmt.Errorf("\"%s\" is not integer", str)
	}
	if num > math.MaxInt32 || num < math.MinInt32 {
		return 0, fmt.Errorf("%d is not 32-bit integer", num)
	}
	return int32(num), nil
}
func cbrt(param int32) float64 {
	return math.Cbrt(float64(param))
}
