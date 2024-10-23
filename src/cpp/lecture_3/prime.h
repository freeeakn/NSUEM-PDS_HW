#ifndef PRIME_H
#define PRIME_H
#include <cmath>
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
#endif // PRIME_H
