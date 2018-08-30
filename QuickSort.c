#include "QuickSort.h"
#include "Swap.h"

int partition(int a[], int l, int r) {
    int pivo = a[r];
    int i = l-1;
    int j;
    for(j = l; j <= r-1; j++)
        if(a[j] <= pivo) {
            i++;
            swap(a, i, j);
        }
    i++;
    swap(a, i, r);
    return (i);
}
void quickSort(int a[], int l, int r) {
    if(l < r) {
        int q = partition(a, l, r);
        quickSort(a, l, q-1);
        quickSort(a, q+1, r);
    }
}