package main

import (
	"fmt"
	"lectureFourth/RecursiveFunc"
)

func main() {
	fmt.Printf("Sum of digits: %d\n", RecursiveFunc.SumDigitsNumber(12345))

	fmt.Printf("Sum from 0 to 10: %d\n", RecursiveFunc.SumFromZeroToNumber(10))

	fmt.Printf("Fibonacci number at position 10: %d\n", RecursiveFunc.Fibonacci(10))

	fmt.Printf("Factorial of 5: %d\n", RecursiveFunc.Factorial(5))
}
