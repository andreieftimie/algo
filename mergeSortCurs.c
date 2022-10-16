/* C program for Merge Sort */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INFINITY INT_MAX

// Merges two subarrays of A[].
// First subarray is A[l..m]
// Second subarray is A[m+1..r]
void merge(int A[], int p, int q, int r)
{
    int i, j, k;
    int n1 = q - p + 1;
    int n2 = r - q;
  
    /* create temp arrays */
    int L[n1 + 1], R[n2 + 1];
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = A[p + i];
    for (j = 0; j < n2; j++)
        R[j] = A[q + 1 + j];

    R[n2] = L[n1] = INFINITY;

    /* Merge the temp arrays back into A[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    for(k=p; k<=r; k++)
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        }
        else {
            A[k] = R[j];
            j++;
        }
}
  
/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int A[], int p, int r)
{
    if (p < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int q = p + (r - p) / 2;
  
        // Sort first and second halves
        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);
  
        merge(A, p, q, r);
    }
}
  
/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
  
/* Driver code */
int main()
{
    int A[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(A) / sizeof(A[0]);
  
    printf("Given array is \n");
    printArray(A, n);
  
    mergeSort(A, 0, n - 1);
  
    printf("\nSorted array is \n");
    printArray(A, n);
    return 0;
    
}
