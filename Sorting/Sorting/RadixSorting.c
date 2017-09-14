//
//  RadixSorting.c
//  Sorting
//
//  Created by shinxg on 14/09/2017.
//  Copyright © 2017 shinxg. All rights reserved.
//

#include "RadixSorting.h"
//n为数组长度
void RadixSort(int* array, int n){
    int maxnum = getmax(array, n);
    int exp;
    for (exp = 1; maxnum/exp > 0 ; exp = exp * 10) {
        CountSort(array, n, exp);
    }
}


int getmax(int* array, int n){
    int i;
    int maxnum = array[0];
    for (i = 1; i < n; i++) {
        if (array[i] > maxnum) {
            maxnum = array[i];
        }
    }
    return maxnum;
}


//n为数组长度，底数为exp
void CountSort(int* array, int n, int exp){
    int i;
    int j;
    int C[10];
    int output[n];
    
    //initialization
    for (i = 0; i < 10; i++) {
        C[i] = 0;
    }
    //count the repeat times
    for (j = 0; j < n; j++) {
        C[(array[j]/exp)%10]++;
    }
    //count the place
    for (i = 0; i<9; i++) {
        C[i+1] = C[i+1] + C[i];
    }
    
    //get the sorted array
    for (j = n-1; j>=0; j--) {
        output[C[(array[j]/exp)%10] - 1] = array[j];
        C[(array[j]/exp)%10] --;
    }
    
    //copy the output array to the original array
    for (j = 0; j < n; j++) {
        array[j] = output[j];
    }
}
