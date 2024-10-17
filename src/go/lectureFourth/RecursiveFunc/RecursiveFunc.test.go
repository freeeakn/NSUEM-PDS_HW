package RecursiveFunc

import (
	"testing"
)

func TestSumDigitsNumber(t *testing.T) {
	result := SumDigitsNumber(12345)
	expected := 15
	if result != expected {
		t.Errorf("SumDigitsNumber(12345) = %d; want %d", result, expected)
	}
}

func TestSumDigitsNumberAllNines(t *testing.T) {
	result := SumDigitsNumber(99999)
	expected := 45
	if result != expected {
		t.Errorf("SumDigitsNumber(99999) = %d; want %d", result, expected)
	}
}

func TestSumDigitsNumberAlternatingDigits(t *testing.T) {
	result := SumDigitsNumber(121212)
	expected := 9
	if result != expected {
		t.Errorf("SumDigitsNumber(121212) = %d; want %d", result, expected)
	}
}

func TestSumDigitsNumberWithLeadingZero(t *testing.T) {
	result := SumDigitsNumber(012345)
	expected := 15
	if result != expected {
		t.Errorf("SumDigitsNumber(012345) = %d; want %d", result, expected)
	}
}

func TestSumDigitsNumberSmallestPositiveInt(t *testing.T) {
	result := SumDigitsNumber(1)
	expected := 1
	if result != expected {
		t.Errorf("SumDigitsNumber(1) = %d; want %d", result, expected)
	}
}

func TestSumDigitsNumberMixedZeros(t *testing.T) {
	result := SumDigitsNumber(10203040)
	expected := 10
	if result != expected {
		t.Errorf("SumDigitsNumber(10203040) = %d; want %d", result, expected)
	}
}

func TestSumFromZeroToNumberZero(t *testing.T) {
	result := SumFromZeroToNumber(0)
	expected := 0
	if result != expected {
		t.Errorf("SumFromZeroToNumber(0) = %d; want %d", result, expected)
	}
}

func TestSumFromZeroToNumberPositive(t *testing.T) {
	result := SumFromZeroToNumber(5)
	expected := 15
	if result != expected {
		t.Errorf("SumFromZeroToNumber(5) = %d; want %d", result, expected)
	}
}

func TestSumFromZeroToNumberLargePositive(t *testing.T) {
	result := SumFromZeroToNumber(1000)
	expected := 500500
	if result != expected {
		t.Errorf("SumFromZeroToNumber(1000) = %d; want %d", result, expected)
	}
}

func TestSumFromZeroToNumberNegative(t *testing.T) {
	result := SumFromZeroToNumber(-5)
	expected := 0
	if result != expected {
		t.Errorf("SumFromZeroToNumber(-5) = %d; want %d", result, expected)
	}
}

func TestSumFromZeroToNumberLargePositiveInteger(t *testing.T) {
	result := SumFromZeroToNumber(10000)
	expected := 50005000
	if result != expected {
		t.Errorf("SumFromZeroToNumber(10000) = %d; want %d", result, expected)
	}
}
