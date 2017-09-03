//
//  MaxSubArray.h
//  MaxSubArray
//
//  Created by shinxg on 03/09/2017.
//  Copyright © 2017 shinxg. All rights reserved.
//

#ifndef MaxSubArray_h
#define MaxSubArray_h

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
typedef struct subArray{
    int left;
    int right;
    int sum;
}SUBARRAY;

//this is the conquer part
//find the maxium subarray across the two sides of the raw array
SUBARRAY* FindMaxCrossingSubarray(int* array, int low, int mid, int high);

//this is the divide part
//find the maxium subarray
SUBARRAY* FindMaxiumSubArray(int* array, int low, int high);

#endif /* MaxSubArray_h */
