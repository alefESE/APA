#include "InsertionSort.h"
#include "Swap.h"

void insertionSort(int a[], int n) {
    int i, j;
    i = 1;

    while(i < n) {
        j = i;
        while(j > 0 && a[j-1] > a[j]) {
            swap(a, j, j-1);
            j--;
        }
        i++;
    }
}