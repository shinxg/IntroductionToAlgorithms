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

int HoarePartition(int* array, int p, int r){
    int pivot = array[p];
    int i = p - 1;
    int j = r + 1;
    
    while (true) {
        do {
            i = i + 1;
        } while (array[i] < pivot);
        do {
            j = j - 1;
        } while (array[j] > pivot);
        if (i < j) {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        } else {
            return j;
        }
    }
}

void QuickSort1(int* array, int p, int r){
    if (p < r) {
        int q = Partition(array, p, r);
        QuickSort1(array, q + 1, r);
        QuickSort1(array, p, q - 1);
    }
}

void QuickSort2(int* array, int p, int r){
    if (p < r) {
        int q = HoarePartition(array, p, r);
        QuickSort2(array, q + 1, r);
        QuickSort2(array, p, q);//different here
    }
}
