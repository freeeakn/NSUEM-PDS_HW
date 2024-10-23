package RecursiveFunc

import (
	"testing"
)

func TestSumDigitsNumber(t *testing.T) {
	result := SumDigitsNumber(12345)
	expected := 15
	if result != expected {
		t.Errorf("SumDigitsNumber(12345) = %d; want %d", result, expected)
	} else {
		t.Log("SumDigitsNumber test passed")
	}
}

func TestSumDigitsNumberAllNines(t *testing.T) {
	result := SumDigitsNumber(99999)
	expected := 45
	if result != expected {
		t.Errorf("SumDigitsNumber(99999) = %d; want %d", result, expected)
	} else {
		t.Log("SumDigitsNumber All Nines test passed")
	}
}

func TestSumDigitsNumberAlternatingDigits(t *testing.T) {
	result := SumDigitsNumber(121212)
	expected := 9
	if result != expected {
		t.Errorf("SumDigitsNumber(121212) = %d; want %d", result, expected)
	} else {
		t.Log("SumDigitsNumber Alternating Digits test passed")
	}
}

func TestSumDigitsNumberSmallestPositiveInt(t *testing.T) {
	result := SumDigitsNumber(1)
	expected := 1
	if result != expected {
		t.Errorf("SumDigitsNumber(1) = %d; want %d", result, expected)
	} else {
		t.Log("SumDigitsNumber Smallest Positive Int test passed")
	}
}

func TestSumDigitsNumberMixedZeros(t *testing.T) {
	result := SumDigitsNumber(10203040)
	expected := 10
	if result != expected {
		t.Errorf("SumDigitsNumber(10203040) = %d; want %d", result, expected)
	} else {
		t.Log("SumDigitsNumber Mixed Zeros test passed")
	}
}

func TestSumFromZeroToNumberZero(t *testing.T) {
	result := SumFromZeroToNumber(0)
	expected := 0
	if result != expected {
		t.Errorf("SumFromZeroToNumber(0) = %d; want %d", result, expected)
	} else {
		t.Log("SumFromZeroToNumber Zero test passed")
	}
}

func TestSumFromZeroToNumberPositive(t *testing.T) {
	result := SumFromZeroToNumber(5)
	expected := 15
	if result != expected {
		t.Errorf("SumFromZeroToNumber(5) = %d; want %d", result, expected)
	} else {
		t.Log("SumFromZeroToNumber Positive test passed")
	}
}

func TestSumFromZeroToNumberLargePositive(t *testing.T) {
	result := SumFromZeroToNumber(1000)
	expected := 500500
	if result != expected {
		t.Errorf("SumFromZeroToNumber(1000) = %d; want %d", result, expected)
	} else {
		t.Log("SumFromZeroToNumber Positive test passed")
	}
}

func TestSumFromZeroToNumberLargePositiveInteger(t *testing.T) {
	result := SumFromZeroToNumber(10000)
	expected := 50005000
	if result != expected {
		t.Errorf("SumFromZeroToNumber(10000) = %d; want %d", result, expected)
	} else {
		t.Log("SumFromZeroToNumber Large Positive Integer test passed")
	}
}

func TestSumFromZeroToNumberMaxInt(t *testing.T) {
	result := SumFromZeroToNumber(1000000)
	expected := 500000500000
	if result != expected {
		t.Errorf("SumFromZeroToNumber(1000000) = %d; want %d", result, expected)
	} else {
		t.Log("SumFromZeroToNumber MaxInt test passed")
	}
}

func TestSumFromZeroToNumberMinInt(t *testing.T) {
	result := SumFromZeroToNumber(0)
	expected := 0
	if result != expected {
		t.Errorf("SumFromZeroToNumber(0) = %d; want %d", result, expected)
	} else {
		t.Log("SumFromZeroToNumber MinInt test passed")
	}
}

func TestFibonacciLargePositiveInteger(t *testing.T) {
	result := Fibonacci(30)
	expected := 832040
	if result != expected {
		t.Errorf("Fibonacci(30) = %d; want %d", result, expected)
	} else {
		t.Log("Fibonacci Large Positive Integer test passed")
	}
}

func TestFibonacciZero(t *testing.T) {
	result := Fibonacci(0)
	expected := 0
	if result != expected {
		t.Errorf("Fibonacci(0) = %d; want %d", result, expected)
	} else {
		t.Log("Fibonacci Zero test passed")
	}
}

func TestFibonacciOne(t *testing.T) {
	result := Fibonacci(1)
	expected := 1
	if result != expected {
		t.Errorf("Fibonacci(1) = %d; want %d", result, expected)
	} else {
		t.Log("Fibonacci One test passed")
	}
}

func TestFibonacciTwo(t *testing.T) {
	result := Fibonacci(2)
	expected := 1
	if result != expected {
		t.Errorf("Fibonacci(2) = %d; want %d", result, expected)
	} else {
		t.Log("Fibonacci Two test passed")
	}
}

func TestFactorialZero(t *testing.T) {
	result := Factorial(0)
	expected := 1
	if result != expected {
		t.Errorf("Factorial(0) = %d; want %d", result, expected)
	} else {
		t.Log("Factorial Zero test passed")
	}
}

func TestFactorialOne(t *testing.T) {
	result := Factorial(1)
	expected := 1
	if result != expected {
		t.Errorf("Factorial(1) = %d; want %d", result, expected)
	} else {
		t.Log("Factorial One test passed")
	}
}

func TestFactorialLargePositiveInteger(t *testing.T) {
	result := Factorial(10)
	expected := 3628800
	if result != expected {
		t.Errorf("Factorial(10) = %d; want %d", result, expected)
	} else {
		t.Log("Factorial Large Positive Integer test passed")
	}
}

func TestFactorialMaxInt(t *testing.T) {
	result := Factorial(20)
	expected := 2432902008176640000
	if result != expected {
		t.Errorf("Factorial(20) = %d; want %d", result, expected)
	} else {
		t.Log("Factorial Max Int test passed")
	}
}

func TestFibonacciMemoizedNegative(t *testing.T) {
	result := FibonacciMemoized(-1, make(map[int]int))
	expected := -1
	if result != expected {
		t.Errorf("FibonacciMemoized(-1) = %d; want %d", result, expected)
	} else {
		t.Log("FibonacciMemoized Negative test passed")
	}
}

func TestFibonacciMemoizedThree(t *testing.T) {
	memo := make(map[int]int)
	result := FibonacciMemoized(3, memo)
	expected := 2
	if result != expected {
		t.Errorf("FibonacciMemoized(3) = %d; want %d", result, expected)
	} else {
		t.Log("FibonacciMemoized Three test passed")
	}
}

func TestFibonacciMemoizedFour(t *testing.T) {
	memo := make(map[int]int)
	result := FibonacciMemoized(4, memo)
	expected := 3
	if result != expected {
		t.Errorf("FibonacciMemoized(4) = %d; want %d", result, expected)
	} else {
		t.Log("FibonacciMemoized Four test passed")
	}
}

func TestFibonacciMemoizedTwenty(t *testing.T) {
	result := FibonacciMemoized(20, make(map[int]int))
	expected := 6765
	if result != expected {
		t.Errorf("FibonacciMemoized(20) = %d; want %d", result, expected)
	} else {
		t.Log("FibonacciMemoized Twenty test passed")
	}
}

func TestFibonacciIterativeArrayNegative(t *testing.T) {
	result := FibonacciIterativeArray(-1)
	expected := -1
	if result != expected {
		t.Errorf("FibonacciIterativeArray(-1) = %d; want %d", result, expected)
	} else {
		t.Log("FibonacciIterativeArray Negative test passed")
	}
}

func TestFibonacciIterativeArrayTwo(t *testing.T) {
	result := FibonacciIterativeArray(2)
	expected := 1
	if result != expected {
		t.Errorf("FibonacciIterativeArray(2) = %d; want %d", result, expected)
	} else {
		t.Log("FibonacciIterativeArray Two test passed")
	}
}

func TestFibonacciIterativeArrayTen(t *testing.T) {
	result := FibonacciIterativeArray(10)
	expected := 55
	if result != expected {
		t.Errorf("FibonacciIterativeArray(10) = %d; want %d", result, expected)
	} else {
		t.Log("FibonacciIterativeArray Ten test passed")
	}
}

func TestFibonacciIterativeArrayEleven(t *testing.T) {
	result := FibonacciIterativeArray(11)
	expected := 89
	if result != expected {
		t.Errorf("FibonacciIterativeArray(11) = %d; want %d", result, expected)
	} else {
		t.Log("FibonacciIterativeArray Eleven test passed")
	}
}

func TestFibonacciIterativeOnTheFlyZero(t *testing.T) {
	result := FibonacciIterativeOnTheFly(0)
	expected := 0
	if result != expected {
		t.Errorf("FibonacciIterativeOnTheFly(0) = %d; want %d", result, expected)
	} else {
		t.Log("FibonacciIterativeOnTheFly Zero test passed")
	}
}

func TestFibonacciIterativeOnTheFlyOne(t *testing.T) {
	result := FibonacciIterativeOnTheFly(1)
	expected := 1
	if result != expected {
		t.Errorf("FibonacciIterativeOnTheFly(1) = %d; want %d", result, expected)
	} else {
		t.Log("FibonacciIterativeOnTheFly One test passed")
	}
}

func TestFibonacciIterativeOnTheFlyThirty(t *testing.T) {
	result := FibonacciIterativeOnTheFly(30)
	expected := 832040
	if result != expected {
		t.Errorf("FibonacciIterativeOnTheFly(30) = %d; want %d", result, expected)
	} else {
		t.Log("FibonacciIterativeOnTheFly Thirty test passed")
	}
}
