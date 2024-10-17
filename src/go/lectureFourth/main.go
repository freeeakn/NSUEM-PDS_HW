package main
import (
	"fmt"
	"lectureFourth/SeveralRecursiveFunctions"
)

func main() {
  fmt.Printf("Sum of digits: %d\n", SeveralRecursiveFunctions.SumDigitsNumber(12345))

  fmt.Printf("Sum from 0 to 10: %d\n", SeveralRecursiveFunctions.SumFromZeroToNumber(10))

  fmt.Printf("Fibonacci number at position 10: %d\n", SeveralRecursiveFunctions.Fibonacci(10))

  fmt.Printf("Factorial of 5: %d\n", SeveralRecursiveFunctions.Factorial(5))
}