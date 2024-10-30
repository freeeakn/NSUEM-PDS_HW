#ifndef GCD_H
#define GCD_H

#include <algorithm>

class GCD {
private:
  int iterations1, iterations2, iterations3;

public:
  GCD() : iterations1(0), iterations2(0), iterations3(0) {}

  int gcd1(int m, int n) {
    this->iterations1 = 0;
    int max = std::max(m, n);
    int *divisors = new int[max];
    int count = 0;
    for (int i = 1; i <= max; i++) {
      this->iterations1++;
      if (m % i == 0 && n % i == 0) {
        divisors[count++] = i;
      }
    }
    int gcd = divisors[count - 1];
    delete[] divisors;
    return gcd;
  }

  int getIterations1() const { return this->iterations1; }

  int gcd2(int m, int n) {
    this->iterations2 = 0;
    int min = std::min(m, n);
    for (int i = min; i >= 1; i--) {
      this->iterations2++;
      if (m % i == 0 && n % i == 0)
        return i;
    }
    return 1;
  }

  int getIterations2() const { return this->iterations2; }

  int gcd3(int m, int n) {
    this->iterations3 = 0;
    while (n != 0) {
      this->iterations3++;
      int temp = n;
      n = m % n;
      m = temp;
    }
    return m;
  }

  int getIterations3() const { return this->iterations3; }
};

#endif // GCD_H