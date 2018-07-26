#include "InsertionSort.h"
#include "SelectionSort.h"
#ifdef _WIN32
#include <windows.h>
#include <winbase.h>
#elif __LINUX__
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
    int *a = malloc(sizeof(int) * n);
    int *b = malloc(sizeof(int) * n);
    int i;
    for(i = 1; i <= n; i++) {
        a[i-1] = atoi(argv[i]);
        b[i-1] = a[i-1];
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
    insertionSort(a, n);
    QueryPerformanceCounter(&li);
    tempo = ((double)li.QuadPart-ini)/freq;
    printf("Tempo do InsertionSort: %.20f ms\n", tempo);

    QueryPerformanceCounter(&li);
    ini = li.QuadPart;
    selectionSort(b, n);
    QueryPerformanceCounter(&li);
    tempo = ((double)li.QuadPart-ini)/freq;
    printf("Tempo do SelectionSort: %.20f ms\n", tempo);

#elif __LINUX__
    clock_t ini, fim;
    ini = clock();
    insertionSort(a, n);
    fim = clock();
    printf("Tempo do InsertionSort: %.20f ms\n", ((double)(fim - ini) / CLOCKS_PER_SEC) * 1000.0);

    ini = clock();
    selectionSort(b, n);
    fim = clock();
    printf("Tempo do SelectionSort: %.20f ms\n", ((double)(fim - ini) / CLOCKS_PER_SEC) * 1000.0);
#endif

    printf("\nArray ordenado por InsertionSort:\n");
    for(i = 0; i < n; i++) 
        printf("%d ", a[i]);
    
    printf("\nArray ordenado por SelectionSort:\n");
    for(i = 0; i < n; i++) 
        printf("%d ", b[i]);
}