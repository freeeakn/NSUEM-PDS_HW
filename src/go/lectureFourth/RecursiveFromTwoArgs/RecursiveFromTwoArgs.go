package RecursiveFromTwoArgs

func EuclideanAlgorithm(a, b int) int {
	if b == 0 {
		return a
	}
	return EuclideanAlgorithm(b, a%b)
}

// power - функция возведения в степень
func Power(base float64, exponent int) float64 {
	// Базовый случай: любое число в степени 0 равно 1
	if exponent == 0 {
		return 1
	}

	// Если показатель степени положителен
	if exponent > 0 {
		// Рекурсивный вызов с уменьшенным показателем степени
		return base * Power(base, exponent-1)
	}

	// Если показатель степени отрицателен
	return 1 / Power(base, -exponent)
}
