#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int insertSort(int *arr, int length) {
  for (int i = 1; i < length; i++) {
    int j = i - 1;
    int temp = arr[i];
    while (j >= 0 && arr[j] > temp) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = temp;
  }
  return 0;
}

int main() {
  int array[] = {6, 4, 2, 8, 1, 9, 3, 5, 7, 0};
  int length = sizeof(array)/sizeof(array[0]);
  printArray(array, length);
  insertSort(array, length);
  printArray(array, length);
  return 0;
}