#ifndef LINEAR_SEARCH_H
#define LINEAR_SEARCH_H

int linearSearch(int arr[], size_t size, int target) {
  int comparisons = 0;
  for (size_t i = 0; i < size; i++) {
    comparisons++;
    if (arr[i] == target) {
      return comparisons;
    }
  }
  return comparisons;
}

#endif // LINEAR_SEARCH_H