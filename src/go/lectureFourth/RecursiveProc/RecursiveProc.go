package RecursiveProc

import (
	"fmt"
)

func FromOneToN(number int) {
	if number > 0 {
		FromOneToN(number - 1)
		fmt.Printf("%d ", number)
	}
}

func FromNtoOne(number int) {
	if number > 0 {
		fmt.Printf("%d ", number)
		FromNtoOne(number - 1)
	}
}

func PrintNumbers(negative, positive int) {
	if negative <= positive {
		fmt.Printf("%d ", negative)
		PrintNumbers(negative+1, positive)
	}
}

func FromMinusNToPlusN(number int) {
	PrintNumbers(-number, number)
}

func EvenFromZeroToN(number int) {
	if number%2 == 0 {
		fmt.Printf("%d ", number)
		EvenFromZeroToN(number - 2)
	}
}
