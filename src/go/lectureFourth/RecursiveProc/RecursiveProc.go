package RecursiveProc

import (
	"fmt"
)

func FromOneToN(number int) {
	if number > 0 {
		FromOneToN(number - 1)
		fmt.Printf("%d \n", number)
	}
}

func FromNtoOne(number int) {
	if number > 0 {
		fmt.Printf("%d \n", number)
		FromNtoOne(number - 1)
	}
}

func PrintNumbers(negative, positive int) {
	if negative <= positive {
		fmt.Printf("%d \n", negative)
		PrintNumbers(negative+1, positive)
	}
}

func FromMinusNToPlusN(number int) {
	PrintNumbers(-number, number)
}
