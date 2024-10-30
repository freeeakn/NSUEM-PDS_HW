package RecursiveFromTwoArgs

func EuclideanAlgorithm(a, b int) int {
	if b == 0 {
		return a
	}
	return EuclideanAlgorithm(b, a%b)
}

func Power(base float64, exponent int) float64 {
	if exponent == 0 {
		return 1
	}

	if exponent > 0 {
		return base * Power(base, exponent-1)
	}

	return 1 / Power(base, -exponent)
}
