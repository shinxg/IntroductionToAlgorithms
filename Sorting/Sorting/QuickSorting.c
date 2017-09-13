//
//  QuickSorting.c
//  Sorting
//
//  Created by shinxg on 13/09/2017.
//  Copyright © 2017 shinxg. All rights reserved.
//

#include "QuickSorting.h"
int Partition(int* array, int p, int r){
    int i = p - 1;
    int pivot = array[r];
    int j;
    for (j = p; j<r; j++) {
        if (array[j] < pivot) {
            i ++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    array[r] = array[i+1];
    array[i+1] = pivot;
    return i+1;
}

void QuickSort(int* array, int p, int r){
    if (p < r) {
        int q = Partition(array, p, r);
        QuickSort(array, q + 1, r);
        QuickSort(array, p, q - 1);
    }
}
