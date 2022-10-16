#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int heapSort(int *arr, int length) {
  for (int i = length / 2 - 1; i >= 0; i--) {
    int j = i;
    while (j * 2 + 1 < length) {
      int k = j * 2 + 1;
      if (k + 1 < length && arr[k] < arr[k + 1]) {
        k++;
      }
      if (arr[j] < arr[k]) {
        int temp = arr[j];
        arr[j] = arr[k];
        arr[k] = temp;
        j = k;
      } else {
        break;
      }
    }
  }
  for (int i = length - 1; i > 0; i--) {
    int temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;
    int j = 0;
    while (j * 2 + 1 < i) {
      int k = j * 2 + 1;
      if (k + 1 < i && arr[k] < arr[k + 1]) {
        k++;
      }
      if (arr[j] < arr[k]) {
        int temp = arr[j];
        arr[j] = arr[k];
        arr[k] = temp;
        j = k;
      } else {
        break;
      }
    }
  }
  return 0;
}

int main() {
  int array[] = {6, 4, 2, 8, 1, 9, 3, 5, 7, 0};
  int length = sizeof(array)/sizeof(array[0]);
  printArray(array, length);
  heapSort(array, length);
  printArray(array, length);
  return 0;
}