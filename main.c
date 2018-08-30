#include "InsertionSort.h"
#include "SelectionSort.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include "CountingSort.h"
#include "HeapSort.h"
#ifdef _WIN32
#include <windows.h>
#include <winbase.h>
#elif defined(__LINUX__) || (defined(__APPLE__) && defined(__MACH__))
#include <time.h>
#endif
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Modo de uso:\n");
        printf("Ordena <num1> <num2> <...>\n");
        return 0;
    }

    int n = argc - 1;
    int *insertion = malloc(sizeof(int) * n);
    int *selection = malloc(sizeof(int) * n);
    int *quick = malloc(sizeof(int) * n);
    int *merge = malloc(sizeof(int) * n);
    int *countA = malloc(sizeof(int) * n);
    int *countB = malloc(sizeof(int) * n);
    int k = 0;
    int *heap = malloc(sizeof(int) * n);
    int i;
    for(i = 0; i <= n-1; i++) {
        insertion[i] = atoi(argv[i + 1]);
        selection[i] = insertion[i];
        quick[i] = insertion[i];
        merge[i] = insertion[i];
        heap[i] = insertion[i];
        countA[i] = insertion[i];
        if(countA[i] > k)
            k = countA[i];
    }
#ifdef _WIN32
    LARGE_INTEGER li;
    double freq = 0.0;
    __int64 ini = 0;
    double tempo;
    QueryPerformanceFrequency(&li);
    freq = ((double)li.QuadPart)/1000.0;//micro segundos
    QueryPerformanceCounter(&li);
    ini = li.QuadPart;
    insertionSort(insertion, n);
    QueryPerformanceCounter(&li);
    tempo = ((double)li.QuadPart-ini)/freq;
    printf("Tempo do InsertionSort: %.20f ms\n", tempo);

    QueryPerformanceCounter(&li);
    ini = li.QuadPart;
    selectionSort(selection, n);
    QueryPerformanceCounter(&li);
    tempo = ((double)li.QuadPart-ini)/freq;
    printf("Tempo do SelectionSort: %.20f ms\n", tempo);

    QueryPerformanceCounter(&li);
    ini = li.QuadPart;
    quickSort(quick, 0, n-1);
    QueryPerformanceCounter(&li);
    tempo = ((double)li.QuadPart-ini)/freq;
    printf("Tempo do QuickSort: %.20f ms\n", tempo);

    QueryPerformanceCounter(&li);
    ini = li.QuadPart;
    mergeSort(merge, 0, n-1);
    QueryPerformanceCounter(&li);
    tempo = ((double)li.QuadPart-ini)/freq;
    printf("Tempo do MergeSort: %.20f ms\n", tempo);

    QueryPerformanceCounter(&li);
    ini = li.QuadPart;
    countingSort(countA, countB, n, k);
    QueryPerformanceCounter(&li);
    tempo = ((double)li.QuadPart-ini)/freq;
    printf("Tempo do CountingSort: %.20f ms\n", tempo);

    QueryPerformanceCounter(&li);
    ini = li.QuadPart;
    heapSort(heap, n);
    QueryPerformanceCounter(&li);
    tempo = ((double)li.QuadPart-ini)/freq;
    printf("Tempo do HeapSort: %.20f ms\n", tempo);

#elif defined(__LINUX__) || (defined(__APPLE__) && defined(__MACH__))
    clock_t ini, fim;
    ini = clock();
    insertionSort(insertion, n);
    fim = clock();
    printf("Tempo do InsertionSort: %.20f ms\n", ((double)(fim - ini) / CLOCKS_PER_SEC) * 1000.0);

    ini = clock();
    selectionSort(selection, n);
    fim = clock();
    printf("Tempo do SelectionSort: %.20f ms\n", ((double)(fim - ini) / CLOCKS_PER_SEC) * 1000.0);

    ini = clock();
    quickSort(quick, 0, n-1);
    fim = clock();
    printf("Tempo do QuickSort: %.20f ms\n", ((double)(fim - ini) / CLOCKS_PER_SEC) * 1000.0);

    ini = clock();
    mergeSort(merge, 0, n-1);
    fim = clock();
    printf("Tempo do MergeSort: %.20f ms\n", ((double)(fim - ini) / CLOCKS_PER_SEC) * 1000.0);

    ini = clock();
    countingSort(countA, countB, n, k);
    fim = clock();
    printf("Tempo do CoutingSort: %.20f ms\n", ((double)(fim - ini) / CLOCKS_PER_SEC) * 1000.0);

    ini = clock();
    heapSort(heap, n);
    fim = clock();
    printf("Tempo do HeapSort: %.20f ms\n", ((double)(fim - ini) / CLOCKS_PER_SEC) * 1000.0);
#endif

    printf("\nArray ordenado por InsertionSort:\n");
    for(i = 0; i < n; i++) 
        printf("%d ", insertion[i]);
    
    printf("\nArray ordenado por SelectionSort:\n");
    for(i = 0; i < n; i++) 
        printf("%d ", selection[i]);

    printf("\nArray ordenado por QuickSort:\n");
    for(i = 0; i < n; i++) 
        printf("%d ", quick[i]);
    
    printf("\nArray ordenado por MergeSort:\n");
    for(i = 0; i < n; i++) 
        printf("%d ", merge[i]);
    
    printf("\nArray ordenado por CountingSort:\n");
    for(i = 0; i < n; i++) 
        printf("%d ", countB[i]);

    printf("\nArray ordenado por HeapSort:\n");
    for(i = 0; i < n; i++) 
        printf("%d ", heap[i]);
}