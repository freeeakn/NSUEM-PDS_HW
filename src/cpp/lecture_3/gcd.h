#ifndef GCD_H
#define GCD_H
#include <algorithm>
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
#endif // GCD_H
