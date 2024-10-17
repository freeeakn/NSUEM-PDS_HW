#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

int binarySearch(int arr[], size_t size, int target) {
  int comparisons = 0;
  int left = 0;
  int right = size - 1;
  while (left <= right) {
    comparisons++;
    int mid = (left + right) / 2;
    if (arr[mid] == target) {
      return comparisons;
    } else if (arr[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return comparisons;
}

#endif // BINARY_SEARCH_H