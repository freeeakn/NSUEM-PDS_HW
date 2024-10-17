#include <algorithm>
#include <chrono>
#include <cmath>
#include <iomanip>
#include <iostream>

template <typename Func> double measureTime(Func func) {
  auto start = std::chrono::high_resolution_clock::now();
  func();
  auto end = std::chrono::high_resolution_clock::now();
  return std::chrono::duration_cast<std::chrono::microseconds>(end - start)
             .count() /
         1000000.0;
}

bool isPrime1(int n) {
  for (int i = 2; i <= n; i++) {
    if (n % i == 0)
      return false;
  }
  return true;
}

bool isPrime2(int n) {
  for (int i = 2; i <= n; i += 2) {
    if (n % i == 0)
      return false;
  }
  return true;
}

bool isPrime3(int n) {
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0)
      return false;
  }
  return true;
}

bool isPrime4(int n) {
  for (int i = 2; i <= sqrt(n); i += 2) {
    if (n % i == 0)
      return false;
  }
  return true;
}

// Алгоритмы вычисления НОД
int gcd1(int m, int n) {
  int max = std::max(m, n);
  // int min = std::min(m, n);
  int *divisors = new int[max];
  int count = 0;
  for (int i = 1; i <= max; i++) {
    if (m % i == 0 && n % i == 0) {
      divisors[count++] = i;
    }
  }
  int gcd = divisors[count - 1];
  delete[] divisors;
  return gcd;
}

int gcd2(int m, int n) {
  int min = std::min(m, n);
  for (int i = min; i >= 1; i--) {
    if (m % i == 0 && n % i == 0)
      return i;
  }
  return 1;
}

int gcd3(int m, int n) {
  int min = std::min(m, n);
  for (int i = 1; i <= min; i++) {
    if (m % i == 0 && n % i == 0)
      return i;
  }
  return 1;
}

int gcd4(int m, int n) {
  while (n != 0) {
    int temp = n;
    n = m % n;
    m = temp;
  }
  return m;
}

int main() {
  std::cout << "Алгоритмы проверки числа на простоту:\n";
  std::cout << "N\tisPrime1\tisPrime2\tisPrime3\tisPrime4\n";
  for (int n = 100; n <= 1000000; n += 100000) {
    double time1 = measureTime([n]() { isPrime1(n); });
    double time2 = measureTime([n]() { isPrime2(n); });
    double time3 = measureTime([n]() { isPrime3(n); });
    double time4 = measureTime([n]() { isPrime4(n); });
    std::cout << n << "\t" << time1 << "\t\t" << time2 << "\t\t" << time3
              << "\t\t" << time4 << "\n";
  }

  std::cout << "\nАлгоритмы вычисления НОД:\n";
  std::cout << "M\tN\t\tgcd1\t\tgcd2\t\tgcd3\t\tgcd4\n";
  for (int m = 100; m <= 1000000; m += 100000) {
    for (int n = 100; n <= 1000000; n += 100000) {
      double time1 = measureTime([m, n]() { gcd1(m, n); });
      double time2 = measureTime([m, n]() { gcd2(m, n); });
      double time3 = measureTime([m, n]() { gcd3(m, n); });
      double time4 = measureTime([m, n]() { gcd4(m, n); });
      std::cout.width(5);
      std::cout << m << "\t" << n << "\t\t" << time1 << "\t\t" << time2
                << "\t\t" << time3 << "\t\t" << time4 << "\n";
    }
  }

  return 0;
}