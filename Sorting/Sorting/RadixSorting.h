//
//  RadixSorting.h
//  Sorting
//
//  Created by shinxg on 14/09/2017.
//  Copyright © 2017 shinxg. All rights reserved.
//

#ifndef RadixSorting_h
#define RadixSorting_h

#include <stdio.h>

//寻找数组中最大的数并返回
int getmax(int* array, int n);

//n为数组长度
void RadixSort(int* array, int n);

//n为数组长度，底数为exp
void CountSort(int* array, int n, int exp);
#endif /* RadixSorting_h */
