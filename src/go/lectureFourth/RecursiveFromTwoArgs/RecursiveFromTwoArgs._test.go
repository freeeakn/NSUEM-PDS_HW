package RecursiveFromTwoArgs

import (
	"testing"
)

func TestEuclideanAlgorithm(t *testing.T) {
	result := EuclideanAlgorithm(48, 18)
	expected := 6
	if result != expected {
		t.Errorf("EuclideanAlgorithm(48, 18) = %d; want %d", result, expected)
	} else {
		t.Log("EuclideanAlgorithm(48, 18) test passed")
	}
}

func TestPower(t *testing.T) {
	result := Power(2, 3)
	var expected float64 = 8
	if result != expected {
		t.Errorf("Power(2, 3) = %f; want %f", result, expected)
	} else {
		t.Log("Power(2, 3) test passed")
	}

	result = Power(2, -3)
	expected = 0.125
	if result != expected {
		t.Errorf("Power(2, -3) = %f; want %f", result, expected)
	} else {
		t.Log("Power(2, -3) test passed")
	}
}
