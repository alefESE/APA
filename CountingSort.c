#include "CountingSort.h"
#include <stdlib.h>
#include <stdio.h>

void countingSort(int a[], int b[], int n, int k) {
    int i;
    int *c = (int*) malloc(k * sizeof(int));

    for(i = 0; i < k; i++)
        c[i] = 0;

    for(i = 0; i < n; i++)
        ++c[a[i]];

    for(i = 1; i <= k; i++)
        c[i] += c[i-1];

    for(i = n-1; i >= 0; i--) {
        b[c[a[i]]-1] = a[i];
        --c[a[i]];
    }
    
}