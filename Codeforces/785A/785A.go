package main

import "fmt"

func main() {

	var n int
	fmt.Scanf("%d", &n)
	var ans int
	ans = 0
	for i := 0; i < n; i++ {
		var str string
		fmt.Scanf("%s", &str)
		if str[0] == 'I' {
			ans += 20
		} else if str[0] == 'C' {
			ans += 6
		} else if str[0] == 'T' {
			ans += 4
		} else if str[0] == 'D' {
			ans += 12
		} else if str[0] == 'O' {
			ans += 8
		}
	}
	fmt.Printf("%d\n", ans)
}
