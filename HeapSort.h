#ifndef _H_HEAPSORT
#define _H_HEAPSORT
int pai(int x);
int filhoEsquerdo(int i);
int filhoDireito(int i);
void maxHeapify(int a[], int n, int i);
void buildMaxHeap(int a[], int n);
void heapSort(int a[], int n);
#endif