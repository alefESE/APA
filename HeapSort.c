#include "HeapSort.h"
#include "Swap.h"

int pai(int i) {
    return (i-1)/2;
}

int filhoEsquerdo(int i) {
    return 2*i + 1;
}

int filhoDireito(int i) {
    return 2*i + 2;
}

void maxHeapify(int a[], int n, int i) {
    int l = filhoEsquerdo(i);
    int r = filhoDireito(i);
    int maior = i;

    if(l < n && a[l] > a[maior])
        maior = l;
    if(r < n && a[r] > a[maior])
        maior = r;
    if(maior != i) {
        swap(a, i, maior);
        maxHeapify(a, n, maior);
    }
}

void buildMaxHeap(int a[], int n) {
    int i;
    for(i = n/2 - 1; i >=0 ; i--)
        maxHeapify(a, n, i);
}

void heapSort(int a[], int n) {
    buildMaxHeap(a, n);
    int i;
    for(i = n-1; i >=0; i--) {
        swap(a, 0, i);
        maxHeapify(a, i, 0);
    }
}