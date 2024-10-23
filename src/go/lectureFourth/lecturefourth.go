package main

import (
	"fmt"
	"lectureFourth/RecursiveFromTwoArgs"
	"lectureFourth/RecursiveFunc"
	"lectureFourth/RecursiveProc"
	"time"
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

	fmt.Println()
	fmt.Println("\033[1;34mTest timings for recursive functions:\033[0m")
	maxNumber := 40

	//! Рекурсивная функция без оптимизации
	startTime := time.Now()
	fmt.Println(RecursiveFunc.Fibonacci(maxNumber))
	elapsedTime := time.Since(startTime)
	fmt.Printf("Время выполнения рекурсивной функции без оптимизации: %s\n", elapsedTime)

	//! Рекурсивная функция с кеш-памятью
	cache := make(map[int]int)
	startTime = time.Now()
	fmt.Println(RecursiveFunc.FibonacciMemoized(maxNumber, cache))
	elapsedTime = time.Since(startTime)
	fmt.Printf("Время выполнения рекурсивной функции с кеш-памятью: %s\n", elapsedTime)

	//! Итеративная функция с временным массивом
	startTime = time.Now()
	fmt.Println(RecursiveFunc.FibonacciIterativeArray(maxNumber))
	elapsedTime = time.Since(startTime)
	fmt.Printf("Время выполнения итеративной функции с временным массивом: %s\n", elapsedTime)

	//! Итеративная функция с вычислением "на лету"
	startTime = time.Now()
	fmt.Println(RecursiveFunc.FibonacciIterativeOnTheFly(maxNumber))
	elapsedTime = time.Since(startTime)
	fmt.Printf("Время выполнения итеративной функции с вычислением \"на лету\": %s\n", elapsedTime)

	fmt.Println("\nAll tests passed!")
}
