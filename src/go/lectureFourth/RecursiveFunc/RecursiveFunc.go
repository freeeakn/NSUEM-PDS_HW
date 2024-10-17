package RecursiveFunc

func SumDigitsNumber(number int) int {
	if number == 0 {
		return 0
	}
	return number%10 + SumDigitsNumber(number/10)
}

func SumFromZeroToNumber(number int) int {
	if number == 0 {
		return 0
	}
	return number + SumFromZeroToNumber(number-1)
}

func Fibonacci(number int) int {
	if number <= 1 {
		return number
	}
	return Fibonacci(number-1) + Fibonacci(number-2)
}

func Factorial(number int) int {
	if number == 0 || number == 1 {
		return 1
	}
	return number * Factorial(number-1)
}
