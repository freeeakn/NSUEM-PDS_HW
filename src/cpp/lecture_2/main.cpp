#include <cstdlib>
#include <ctime>
#include <iostream>

#include "binary_search.h"
#include "linear_search.h"
#include "search_comparison.h"

int main() {
  srand(time(0));

  std::cout << "Тестирование последовательного поиска:" << std::endl;
  for (int size = 10; size <= 100; size += 10) {
    int arr[size];
    for (int i = 0; i < size; i++) {
      arr[i] = rand() % 100;
    }
    int target = rand() % 100;
    int comparisons = linearSearch(arr, size, target);
    std::cout << "Размер массива: " << size << ", искомый элемент: " << target
              << ", количество сравнений: " << comparisons << std::endl;
  }

  std::cout << "\nТестирование двоичного поиска:" << std::endl;
  for (int size = 10; size <= 100; size += 10) {
    int arr[size];
    for (int i = 0; i < size; i++) {
      arr[i] = rand() % 100;
    }
    std::sort(arr, arr + size);
    int target = rand() % 100;
    int comparisons = binarySearch(arr, size, target);
    std::cout << "Размер массива: " << size << ", искомый элемент: " << target
              << ", количество сравнений: " << comparisons << std::endl;
  }

  std::cout << "\nСравнение сложности алгоритмов поиска:" << std::endl;
  searchComparison();

  return 0;
}