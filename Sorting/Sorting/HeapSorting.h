//
//  HeapSorting.h
//  Sorting
//
//  Created by shinxg on 03/09/2017.
//  Copyright © 2017 shinxg. All rights reserved.
//

#ifndef HeapSorting_h
#define HeapSorting_h

#include <stdio.h>
#include <stdlib.h>

typedef struct heap{
    int* heap;
    int length;
    int heap_size;
}HEAP;

//使数组满足堆的要求
void MaxHeapify(HEAP* heap, int i);

//建立一个堆
void BuildMaxHeap(HEAP* heap);

//实现堆排序
void HeapSort(HEAP* heap);
#endif /* HeapSorting_h */
