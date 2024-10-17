#ifndef SEARCH_COMPARISON_H
#define SEARCH_COMPARISON_H

#include "binary_search.h"
#include "linear_search.h"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>

void searchComparison() {
  srand(time(0));

  std::cout << "Размер массива\tПоследовательный поиск\tДвоичный поиск"
            << std::endl;
  for (size_t size = 20; size <= 500; size += 20) {
    int arr[size];
    for (size_t i = 0; i < size; i++) {
      arr[i] = rand() % 500;
    }
    std::sort(arr, arr + size);
    int target = rand() % 500;
    int linearComparisons = linearSearch(arr, size, target);
    int binaryComparisons = binarySearch(arr, size, target);
    std::cout << size << "\t\t" << linearComparisons << "\t\t\t"
              << binaryComparisons << std::endl;
  }
}

#endif // SEARCH_COMPARISON_H