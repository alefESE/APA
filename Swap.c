#include "Swap.h"

void swap(int a[], int i, int j) {
    int aux = a[i];
    a[i] = a[j];
    a[j] = aux;
}