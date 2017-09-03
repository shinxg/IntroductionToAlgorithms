//
//  MaxSubArray.c
//  MaxSubArray
//
//  Created by shinxg on 03/09/2017.
//  Copyright © 2017 shinxg. All rights reserved.
//

#include "MaxSubArray.h"

//this is the conquer part
//find the maxium subarray across the two sides of the raw array
SUBARRAY* FindMaxCrossingSubarray(int* array, int low, int mid, int high){
    //from mid to low, find the maxium
    int left_sum = INT32_MIN;
    int sum = 0;
    int i;
    SUBARRAY* Cross;
    Cross = malloc(sizeof(SUBARRAY));
    
    for (i = mid; i>=low; i--) {
        sum = sum + array[i];
        if (sum > left_sum) {
            left_sum = sum;
            Cross->left = i;
        }
    }
    
    //from mid+1 to high, find the maxium
    int right_sum = INT32_MIN;
    sum = 0;
    for (i = mid + 1; i <= high; i++) {
        sum = sum + array[i];
        if (sum > right_sum) {
            right_sum = sum;
            Cross->right = i;
        }
    }
    Cross->sum = left_sum + right_sum;
    return Cross;
}

//this is the divide part
//find the maxium subarray
SUBARRAY* FindMaxiumSubArray(int* array, int low, int high){
    SUBARRAY* left;
    SUBARRAY* right;
    SUBARRAY* cross;
    SUBARRAY* final;
    left = malloc(sizeof(SUBARRAY));
    right = malloc(sizeof(SUBARRAY));
    cross = malloc(sizeof(SUBARRAY));
    final = malloc(sizeof(SUBARRAY));
    if (low == high) {
        final->left = low;
        final->right = high;
        final->sum = array[low];
    } else {
        int mid = (low + high)/2;
        //divide
        left = FindMaxiumSubArray(array, low, mid);
        right = FindMaxiumSubArray(array, mid + 1 , high);
        cross = FindMaxCrossingSubarray(array, low, mid, high);
        //conquer
        if (cross->sum >= left->sum && cross->sum >= right->sum) {
            final = cross;
        } else if (left->sum >= cross->sum && left->sum >= right->sum) {
            final = left;
        } else if (right->sum >= cross->sum && right->sum >= left->sum) {
            final = right;
        }
    }
    return final;
}
