#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int mergeSort(int *arr, int length) {
  if (length <= 1) {
    return 0;
  }
  int mid = length / 2;
  mergeSort(arr, mid);
  mergeSort(arr + mid, length - mid);
  int *temp = (int *)malloc(sizeof(int) * length);
  int i = 0;
  int j = mid;
  int k = 0;
  while (i < mid && j < length) {
    if (arr[i] < arr[j]) {
      temp[k++] = arr[i++];
    } else {
      temp[k++] = arr[j++];
    }
  }
  while (i < mid) {
    temp[k++] = arr[i++];
  }
  while (j < length) {
    temp[k++] = arr[j++];
  }
  for (int i = 0; i < length; i++) {
    arr[i] = temp[i];
  }
  free(temp);
  return 0;
}

int main() {
  int array[] = {6, 4, 2, 8, 1, 9, 3, 5, 7, 0};
  int length = sizeof(array)/sizeof(array[0]);
  printArray(array, length);
  mergeSort(array, length);
  printArray(array, length);
  return 0;
}