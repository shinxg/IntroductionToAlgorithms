//
//  MergeSorting.c
//  Sorting
//
//  Created by shinxg on 02/09/2017.
//  Copyright © 2017 shinxg. All rights reserved.
//

#include "MergeSorting.h"
void MergeSorting(int* array, int start, int end){
    if (start < end) {
        int mid = (start + end)/2;
        MergeSorting(array, start, mid);
        MergeSorting(array, mid + 1, end);
        Merge(array, start, mid, end);
    }
}

void Merge(int* array, int start, int mid, int end){
    int leftnum = mid - start + 1;
    int rightnum = end - mid;
    int left[leftnum];
    int right[rightnum];
    int i;
    int j;
    int k;
    //initialize the left and right array
    for (i = 0; i < leftnum; i++) {
        left[i] = array[start+i];
    }
    for (i = 0; i < rightnum; i++) {
        right[i] = array[mid + i + 1];
    }
    //merge left and right array
    i = 0;
    j = 0;
    k = start;
    while (i < leftnum && j < rightnum) {
        if (left[i] < right[j]) {
            array[k] = left[i];
            i ++;
            k ++;
        } else {
            array[k] = right[j];
            j ++;
            k ++;
        }
    }
    if (i >= leftnum) {
        while (j < rightnum) {
            array[k] = right[j];
            j ++;
            k ++;
        }
    } else {
        while (i < leftnum) {
            array[k] = left[i];
            i ++;
            k ++;
        }
    }
}
