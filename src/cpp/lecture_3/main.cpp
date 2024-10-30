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
  Prime prime;
  GCD gcd;

  std::cout << "Алгоритмы проверки числа на простоту:\n";
  std::cout << std::setw(5) << "N" << "\t" << std::setw(10) << "isPrime1"
            << "\t" << std::setw(10) << "isPrime2" << "\t" << std::setw(10)
            << "isPrime3" << "\t" << std::setw(10) << "isPrime4" << "\t"
            << std::setw(10) << "Итерации 1" << "\t" << std::setw(10)
            << "Итерации 2" << "\t" << std::setw(10) << "Итерации 3" << "\t"
            << std::setw(10) << "Итерации 4" << "\n";

  double maxTime = 0;
  for (int n = 101; n <= 15000; n += 500) {
    double time1 = measureTime([n, &prime]() { prime.isPrime1(n); });
    double time2 = measureTime([n, &prime]() { prime.isPrime2(n); });
    double time3 = measureTime([n, &prime]() { prime.isPrime3(n); });
    double time4 = measureTime([n, &prime]() { prime.isPrime4(n); });
    maxTime = std::max(
        maxTime, std::max(time1, std::max(time2, std::max(time3, time4))));
  }

  for (int n = 101; n <= 15000; n += 500) {
    double time1 = measureTime([n, &prime]() { prime.isPrime1(n); });
    double time2 = measureTime([n, &prime]() { prime.isPrime2(n); });
    double time3 = measureTime([n, &prime]() { prime.isPrime3(n); });
    double time4 = measureTime([n, &prime]() { prime.isPrime4(n); });

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
    std::cout << "\t";
    std::cout << std::setw(10) << prime.getIterations1() << "\t";
    std::cout << std::setw(10) << prime.getIterations2() << "\t";
    std::cout << std::setw(10) << prime.getIterations3() << "\t";
    std::cout << std::setw(10) << prime.getIterations4() << "\t";
    std::cout << "\n";
  }

  std::cout << "\nАлгоритмы вычисления НОД:\n";
  std::cout << std::setw(5) << "M" << "\t" << std::setw(5) << "N" << "\t"
            << std::setw(10) << "gcd1" << "\t" << std::setw(10) << "gcd2"
            << "\t" << std::setw(10) << "gcd3" << "\t" << std::setw(10) << "Итерации 1" << "\t"
            << std::setw(10) << "Итерации 2" << "\t" << std::setw(10)
            << "Итерации 3" << "\n";

  maxTime = 0;
  for (int m = 101; m <= 1000; m += 100) {
    for (int n = 123; n <= 1000; n += 132) {
      double time1 = measureTime([m, n, &gcd]() { gcd.gcd1(m, n); });
      double time2 = measureTime([m, n, &gcd]() { gcd.gcd2(m, n); });
      double time3 = measureTime([m, n, &gcd]() { gcd.gcd3(m, n); });
      maxTime = std::max(
          maxTime, std::max(time1, std::max(time2, time3)));
    }
  }

  for (int m = 101; m <= 1000; m += 100) {
    for (int n = 123; n <= 1000; n += 132) {
      double time1 = measureTime([m, n, &gcd]() { gcd.gcd1(m, n); });
      double time2 = measureTime([m, n, &gcd]() { gcd.gcd2(m, n); });
      double time3 = measureTime([m, n, &gcd]() { gcd.gcd3(m, n); });

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
      std::cout << std::setw(10) << gcd.getIterations1() << "\t";
      std::cout << std::setw(10) << gcd.getIterations2() << "\t";
      std::cout << std::setw(10) << gcd.getIterations3() << "\t";
      std::cout << "\n";
    }
  }

  return 0;
}