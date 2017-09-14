//
//  main.c
//  Sorting
//
//  Created by shinxg on 02/09/2017.
//  Copyright © 2017 shinxg. All rights reserved.
//

#include <stdio.h>
#include "MergeSorting.h"
#include "InsertionSorting.h"
#include "SelectSorting.h"
#include "HeapSorting.h"
#include "QuickSorting.h"
#include "CountingSort.h"
#include "RadixSorting.h"

void PrintArray(int* array, int length);

int main(int argc, const char * argv[]) {
    // insert code here...
    int array[6] = {5, 2, 4, 6, 1, 3};
    int A[12] = {0, 7, 2, 1, 5, 6, 7, 4, 4, 5, 6, 2};
    int B[12];
    
    int radixarray[8] = {170, 45, 75, 90, 802, 24, 2, 66};
    RadixSort(radixarray, 8);
    PrintArray(radixarray, 8);
    
    CountingSort(A, B, 7, 12);
    PrintArray(B, 12);
    
    QuickSort2(array, 0, 5);
    PrintArray(array, 6);
    HEAP heap;
    heap.heap = malloc(sizeof(int)*10);
    heap.heap_size = 10;
    heap.length = 10;
    int heaparray[10] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    int i;
    for (i = 0; i < 10; i++) {
        heap.heap[i] = heaparray[i];
    }
    BuildMaxHeap(&heap);
    PrintArray(heap.heap, 10);
    HeapSort(&heap);
    PrintArray(heap.heap, 10);
    
    MergeSorting(array, 0, 5);
    PrintArray(array, 6);
    SelectSorting(array, 6);
    PrintArray(array, 6);
    InsertionSorting(array, 6);
    PrintArray(array, 6);
    
    return 0;
}

void PrintArray(int* array, int length){
    int i;
    for (i = 0; i<length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
