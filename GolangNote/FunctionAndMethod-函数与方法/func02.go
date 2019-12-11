
import "fmt"


func Add(f func(int) int) int {
	arr := []int{1, 2, 3, 4, 5, 6, 7, 8, 9}
	var count int = 0
	for _, num := range arr {
		fmt.Printf("count=%d, num=%d, f(num)=%d\n", count, num, f(num))
		if func(num int) bool {
			return num != 0
		}(f(num)) {
			count++
		}
	}

	return count
}

func main(){
	count := Add(func(b int) int {
		return b % 2
	})
	fmt.Println(count)
}
