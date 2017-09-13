//
//  QuickSorting.h
//  Sorting
//
//  Created by shinxg on 13/09/2017.
//  Copyright © 2017 shinxg. All rights reserved.
//

#ifndef QuickSorting_h
#define QuickSorting_h

#include <stdio.h>
#include <stdbool.h>

int Partition(int* array, int p, int r);
int HoarePartition(int* array, int p, int r);
void QuickSort1(int* array, int p, int r);
void QuickSort2(int* array, int p, int r);
#endif /* QuickSorting_h */
