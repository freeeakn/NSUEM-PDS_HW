package SeveralRecursiveFunctions

func sumDigitsNumber(number int) int {
	if number == 0 {
    return 0
  }
  return number % 10 + sumDigitsNumber(number / 10)
}

func sumFromZeroToNumber(number int) int {
	if number == 0 {
    return 0
  }
  return number + sumFromZeroToNumber(number - 1)
}

func fibonacci(number int) int {
	if number <= 1 {
    return number
  }
  return fibonacci(number - 1) + fibonacci(number - 2)
}

func factorial(number int) int {
	if number == 0 || number == 1 {
    return 1
  }
  return number * factorial(number - 1)
}