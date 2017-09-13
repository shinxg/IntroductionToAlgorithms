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


//优先队列常用于系统调度
//使用堆实现最大优先队列
//返回队列中最大的值
int HeapMaxium(HEAP* heap);

//返回并删除最大值
int HeapExtractMax(HEAP* heap);

//将队列中某一个元素的值增加
void HeapIncreaseKey(HEAP* heap, int i, int newkey);

//将一个新的元素插入优先队列中
void HeapInsertKey(HEAP* heap, int newkey);

#endif /* HeapSorting_h */
