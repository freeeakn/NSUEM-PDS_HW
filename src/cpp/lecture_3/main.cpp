#include "gcd.h"
#include "prime.h"
#include <chrono>
#include <iomanip>
#include <iostream>

template <typename Func> double measureTime(Func &&func) {
  auto start = std::chrono::high_resolution_clock::now();
  std::forward<Func>(func)();
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> duration = end - start;
  return duration.count();
}

void setBackgroundColor(double value, double max) {
  double ratio = value / max;
  if (ratio < 0.1) {
    std::cout << "\033[42m"; // Зеленый фон
  } else if (ratio < 0.3) {
    std::cout << "\033[102m"; // Светло-зеленый фон
  } else if (ratio < 0.5) {
    std::cout << "\033[43m"; // Желтый фон
  } else if (ratio < 0.7) {
    std::cout << "\033[103m"; // Светло-желтый фон
  } else {
    std::cout << "\033[41m"; // Красный фон
  }
}

void resetBackgroundColor() { std::cout << "\033[0m"; }

int main() {
  std::cout << "Алгоритмы проверки числа на простоту:\n";
  std::cout << std::setw(5) << "N" << "\t" << std::setw(10) << "isPrime1"
            << "\t" << std::setw(10) << "isPrime2" << "\t" << std::setw(10)
            << "isPrime3" << "\t" << std::setw(10) << "isPrime4" << "\n";

  double maxTime = 0;
  for (int n = 100; n <= 10000; n += 500) {
    double time1 = measureTime([n]() { isPrime1(n); });
    double time2 = measureTime([n]() { isPrime2(n); });
    double time3 = measureTime([n]() { isPrime3(n); });
    double time4 = measureTime([n]() { isPrime4(n); });
    maxTime = std::max(
        maxTime, std::max(time1, std::max(time2, std::max(time3, time4))));
  }

  for (int n = 100; n <= 10000; n += 500) {
    double time1 = measureTime([n]() { isPrime1(n); });
    double time2 = measureTime([n]() { isPrime2(n); });
    double time3 = measureTime([n]() { isPrime3(n); });
    double time4 = measureTime([n]() { isPrime4(n); });

    std::cout << std::setw(5) << n << "\t";
    setBackgroundColor(time1, maxTime);
    std::cout << std::fixed << std::setprecision(6) << std::setw(10) << time1;
    resetBackgroundColor();
    std::cout << "\t";
    setBackgroundColor(time2, maxTime);
    std::cout << std::fixed << std::setprecision(6) << std::setw(10) << time2;
    resetBackgroundColor();
    std::cout << "\t";
    setBackgroundColor(time3, maxTime);
    std::cout << std::fixed << std::setprecision(6) << std::setw(10) << time3;
    resetBackgroundColor();
    std::cout << "\t";
    setBackgroundColor(time4, maxTime);
    std::cout << std::fixed << std::setprecision(6) << std::setw(10) << time4;
    resetBackgroundColor();
    std::cout << "\n";
  }

  std::cout << "\nАлгоритмы вычисления НОД:\n";
  std::cout << std::setw(5) << "M" << "\t" << std::setw(5) << "N" << "\t"
            << std::setw(10) << "gcd1" << "\t" << std::setw(10) << "gcd2"
            << "\t" << std::setw(10) << "gcd3" << "\t" << std::setw(10)
            << "gcd4" << "\n";

  maxTime = 0;
  for (int m = 100; m <= 10000; m += 500) {
    for (int n = 100; n <= 10000; n += 500) {
      double time1 = measureTime([m, n]() { gcd1(m, n); });
      double time2 = measureTime([m, n]() { gcd2(m, n); });
      double time3 = measureTime([m, n]() { gcd3(m, n); });
      double time4 = measureTime([m, n]() { gcd4(m, n); });
      maxTime = std::max(
          maxTime, std::max(time1, std::max(time2, std::max(time3, time4))));
    }
  }

  for (int m = 100; m <= 10000; m += 500) {
    for (int n = 100; n <= 10000; n += 500) {
      double time1 = measureTime([m, n]() { gcd1(m, n); });
      double time2 = measureTime([m, n]() { gcd2(m, n); });
      double time3 = measureTime([m, n]() { gcd3(m, n); });
      double time4 = measureTime([m, n]() { gcd4(m, n); });

      std::cout << std::setw(5) << m << "\t" << std::setw(5) << n << "\t";
      setBackgroundColor(time1, maxTime);
      std::cout << std::fixed << std::setprecision(6) << std::setw(10) << time1;
      resetBackgroundColor();
      std::cout << "\t";
      setBackgroundColor(time2, maxTime);
      std::cout << std::fixed << std::setprecision(6) << std::setw(10) << time2;
      resetBackgroundColor();
      std::cout << "\t";
      setBackgroundColor(time3, maxTime);
      std::cout << std::fixed << std::setprecision(6) << std::setw(10) << time3;
      resetBackgroundColor();
      std::cout << "\t";
      setBackgroundColor(time4, maxTime);
      std::cout << std::fixed << std::setprecision(6) << std::setw(10) << time4;
      resetBackgroundColor();
      std::cout << "\n";
    }
  }

  return 0;
}