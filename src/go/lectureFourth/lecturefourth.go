package main

import (
	"fmt"
	"lectureFourth/RecursiveFromTwoArgs"
	"lectureFourth/RecursiveFunc"
	"lectureFourth/RecursiveProc"
)

func main() {
	fmt.Println("\033[1;34mStarting tests with RecursiveFunc package:\033[0m")
	fmt.Printf("Sum of digits: %d\n", RecursiveFunc.SumDigitsNumber(12345))

	fmt.Printf("Sum from 0 to 10: %d\n", RecursiveFunc.SumFromZeroToNumber(10))

	fmt.Printf("Fibonacci number at position 10: %d\n", RecursiveFunc.Fibonacci(10))

	fmt.Printf("Factorial of 5: %d\n", RecursiveFunc.Factorial(5))

	fmt.Println("\033[1;34mStarting tests with RecursiveProc package:\033[0m")

	fmt.Println("From 1 to 10:")
	RecursiveProc.FromOneToN(10)

	fmt.Println("\nFrom 10 to 1:")
	RecursiveProc.FromNtoOne(10)

	fmt.Println("\nFrom -5 to 5:")
	RecursiveProc.FromMinusNToPlusN(5)
	fmt.Println()

	fmt.Println("\033[1;34mStarting tests with RecursiveFromTwoArgs package:\033[0m")

	fmt.Println(RecursiveFromTwoArgs.EuclideanAlgorithm(48, 18))   //! 6
	fmt.Println(RecursiveFromTwoArgs.EuclideanAlgorithm(101, 103)) //! 1
	fmt.Println(RecursiveFromTwoArgs.Power(2, 3))                  //! Выводит: 8
	fmt.Println(RecursiveFromTwoArgs.Power(2, -3))                 //! Выводит: 0.125
}
