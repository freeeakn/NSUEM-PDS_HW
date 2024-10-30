#ifndef PRIME_H
#define PRIME_H

#include <cmath>

class Prime {
private:
  int iterations1, iterations2, iterations3, iterations4;

public:
  Prime() : iterations1(0), iterations2(0), iterations3(0), iterations4(0) {}

  bool isPrime1(int n) {
    this->iterations1 = 0;
    for (int i = 2; i <= n; i++) {
      this->iterations1++;
      if (n % i == 0)
        return false;
    }
    return true;
  }

  int getIterations1() const { return this->iterations1; }

  bool isPrime2(int n) {
    this->iterations2 = 0;
    for (int i = 2; i <= n; i += 2) {
      this->iterations2++;
      if (n % i == 0)
        return false;
    }
    return true;
  }

  int getIterations2() const { return this->iterations2; }

  bool isPrime3(int n) {
    this->iterations3 = 0;
    for (int i = 2; i <= sqrt(n); i++) {
      this->iterations3++;
      if (n % i == 0)
        return false;
    }
    return true;
  }

  int getIterations3() const { return this->iterations3; }

  bool isPrime4(int n) {
    this->iterations4 = 0;
    for (int i = 2; i <= sqrt(n); i += 2) {
      this->iterations4++;
      if (n % i == 0)
        return false;
    }
    return true;
  }

  int getIterations4() const { return this->iterations4; }
};

#endif // PRIME_H