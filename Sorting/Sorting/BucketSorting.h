//
//  BucketSorting.h
//  Sorting
//
//  Created by shinxg on 14/09/2017.
//  Copyright © 2017 shinxg. All rights reserved.
//

#ifndef BucketSorting_h
#define BucketSorting_h

#include <stdio.h>
#include <stdlib.h>
//桶排序
void BucketSort(int* array, int n);

//将一个数插入到数组中使得数组仍然为有序的数组
int* Insert(int* list, int count, int number);

#endif /* BucketSorting_h */
