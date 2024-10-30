package RecursiveFunc

func SumDigitsNumber(number uint64) uint64 {
	if number == 0 {
		return 0
	}
	return number%10 + SumDigitsNumber(number/10)
}

func SumFromZeroToNumber(number uint64) uint64 {
	if number == 0 {
		return 0
	}
	return number + SumFromZeroToNumber(number-1)
}

func Fibonacci(number uint64) uint64 {
	if number <= 1 {
		return number
	}
	return Fibonacci(number-1) + Fibonacci(number-2)
}

func Factorial(number uint64) uint64 {
	if number == 0 || number == 1 {
		return 1
	}
	return number * Factorial(number-1)
}

func FibonacciMemoized(n int, memo map[int]int) int {
	if n <= 1 {
		return n
	}
	if result, exists := memo[n]; exists {
		return result
	}
	memo[n] = FibonacciMemoized(n-1, memo) + FibonacciMemoized(n-2, memo)
	return memo[n]
}

func FibonacciIterativeArray(n int) int {
	if n <= 1 {
		return n
	}
	fib := make([]int, n+1)
	fib[0], fib[1] = 0, 1
	for i := 2; i <= n; i++ {
		fib[i] = fib[i-1] + fib[i-2]
	}
	return fib[n]
}

func FibonacciIterativeOnTheFly(n int) int {
	if n <= 1 {
		return n
	}
	a, b := 0, 1
	for i := 2; i <= n; i++ {
		a, b = b, a+b
	}
	return b
}
