package main

import (
	"fmt"
	"lectureFourth/RecursiveFromTwoArgs"
	"lectureFourth/RecursiveFunc"
	"lectureFourth/RecursiveProc"
	"log"
	"os"
	"time"
	"github.com/olekukonko/tablewriter"
)

func main() {

	var (
		count  uint64 = 30
		number uint64
	)

	filename := "lectureFourth_results.csv"
	file, err := os.Create(filename)
	if err != nil {
		fmt.Println(err)
		return
	}
	defer file.Close()

	fmt.Fprintln(file, "\033[1;34mStarting tests with RecursiveFunc package:\033[0m")

	for number = 1; number <= count; number++ {
		fmt.Fprintf(file, "\nSum of %d digits: %d\n", number, RecursiveFunc.SumDigitsNumber(number))        //! Sum of digits
		fmt.Fprintf(file, "Sum from 0 to %d: %d\n", number, RecursiveFunc.SumFromZeroToNumber(number))      //! Sum from zero to number
		fmt.Fprintf(file, "Fibonacci number at position %d: %d\n", number, RecursiveFunc.Fibonacci(number)) //! Sum from zero to number
		fmt.Fprintf(file, "Factorial of %d: %d\n", number, RecursiveFunc.Factorial(uint64(number)))         //! Sum from zero to number
	}

	fmt.Fprintln(file, "\033[1;34mStarting tests with RecursiveProc package:\033[0m")

	for number = 1; number <= count; number++ {
		fmt.Printf("\n\nFrom 1 to %d:\n", number)         //!
		RecursiveProc.FromOneToN(int(number))             //! From 1 to number
		fmt.Printf("\nFrom %d to 1:\n", number)           //!
		RecursiveProc.FromNtoOne(int(number))             //! From number to 1
		fmt.Printf("\nFrom %d to %d:\n", -number, number) //!
		RecursiveProc.FromMinusNToPlusN(int(number))      //! From -number to number
	}

	fmt.Fprintf(file, "\n\033[1;34mStarting tests with RecursiveFromTwoArgs package:\033[0m\n")
	for numberM := 0; numberM < int(count); numberM++ {
		for numberN := 0; numberN < int(count); numberN++ {
			fmt.Fprintf(file, "\nRecursive EuclideanAlgorithm(%d, %d): %d\n", numberM, numberN, RecursiveFromTwoArgs.EuclideanAlgorithm(numberM, numberN))
		}
	}
	for numberM := 0.0; numberM < float64(count); numberM++ {
		for numberN := 0; numberN < 5; numberN++ {
			fmt.Fprintf(file, "\nRecursive Power(%f, %d): %f\n", numberM, numberN, RecursiveFromTwoArgs.Power(numberM, numberN))
		}
	}

	fileTable, err := os.Create("table.txt")
	if err != nil {
		log.Fatal(err)
	}
	defer fileTable.Close()

	fmt.Fprintln(fileTable, "\n\033[1;34mTest timings for recursive functions:\033[0m")
	table := tablewriter.NewWriter(fileTable)
	table.SetHeader([]string{"Func", "result", "time"})

	var maxNumber uint64 = 40

	for number = 0; number < maxNumber; number++ {
		//! Рекурсивная функция без оптимизации
		startTime := time.Now()
		resultInt := RecursiveFunc.Fibonacci(maxNumber)
		elapsedTime := time.Since(startTime)
		table.Append([]string{"Рекурсивная функция без оптимизации", string(resultInt), elapsedTime.String()})

		//! Рекурсивная функция с кеш-памятью
		cache := make(map[int]int)
		startTime = time.Now()
		resultUInt := RecursiveFunc.FibonacciMemoized(int(maxNumber), cache)
		elapsedTime = time.Since(startTime)
		table.Append([]string{"Рекурсивная функция с кеш-памятью", string(resultUInt), elapsedTime.String()})

		//! Итеративная функция с временным массивом
		startTime = time.Now()
		resultUInt = RecursiveFunc.FibonacciIterativeArray(int(maxNumber))
		elapsedTime = time.Since(startTime)
		table.Append([]string{"Итеративная функция с временным массивом", string(resultUInt), elapsedTime.String()})

		//! Итеративная функция с вычислением "на лету"
		startTime = time.Now()
		resultUInt = RecursiveFunc.FibonacciIterativeOnTheFly(int(maxNumber))
		elapsedTime = time.Since(startTime)
		table.Append([]string{"Итеративная функция с вычислением \"на лету\"", string(resultUInt), elapsedTime.String()})
	}
	table.Render()

	fmt.Fprintln(file, "\nAll tests passed!")
}
