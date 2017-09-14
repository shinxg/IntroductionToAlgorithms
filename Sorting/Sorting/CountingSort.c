//
//  CountingSort.c
//  Sorting
//
//  Created by shinxg on 13/09/2017.
//  Copyright © 2017 shinxg. All rights reserved.
//

#include "CountingSort.h"
//k means all number of array A is between [0,k], length means the length of the array
void CountingSort(int* A, int* B, int k, int length){
    //array C used to count the presence times of every different number in array a
    int C[k + 1];
    int i;
    int j;
    //initialization
    for (i = 0; i < k + 1; i++) {
        C[i] = 0;
    }
    //count the presence time
    for (j = 0; j < length; j++) {
        C[A[j]]++;
    }
    //show the number of integers <= a[i]
    for (i = 0; i < k; i ++) {
        C[i+1] = C[i+1] + C[i];
    }
    //sort
    for (j = length - 1; j>=0; j--) {
        //a[j] is at the C[A[j]]'th place
        B[C[A[j]] - 1] = A[j];
        C[A[j]]--;
    }
}
