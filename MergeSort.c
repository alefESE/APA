#include "MergeSort.h"
#include <stdlib.h>

void merge(int a[], int p, int q, int r) {
    int n = r - p + 1;
    int *aux = (int*) malloc(n *sizeof(int));
    int i = p;
    int j = q+1;
    int k = 0;

    while(i <= q && j <= r) {
        if(a[i] < a[j]) {
            aux[k] = a[i];
            i++;
        } else {
            aux[k] = a[j];
            j++;
        }
        k++;
    }

    while(i <= q) {
        aux[k] = a[i];
        k++;
        i++;
    }

    while(j <= r) {
        aux[k] = a[j];
        k++;
        j++;
    }

    for(k = p; k <= r; k++) {
        a[k] = aux[k-p];
    }

    free(aux);
}

void mergeSort(int a[], int p, int r) {
    int q;
    if(p < r) {
        q = ((p + r) / 2);
        mergeSort(a, p, q);
        mergeSort(a, q + 1, r);
        merge(a, p, q, r);
    }
}