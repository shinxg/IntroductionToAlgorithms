//
//  HeapSorting.c
//  Sorting
//
//  Created by shinxg on 03/09/2017.
//  Copyright © 2017 shinxg. All rights reserved.
//

#include "HeapSorting.h"

//使数组满足堆的要求
void MaxHeapify(HEAP* heap, int i){
    //calculate the
    int left = i*2;
    int right = i*2 + 1;
    
    int LargestIndex;
    //judge whether the childs of node i is bigger than it or not
    if ( left <= heap->heap_size && heap->heap[left - 1] > heap->heap[i-1]) {
        LargestIndex = left;
    } else {
        LargestIndex = i;
    }
    if ( right <= heap->heap_size && heap->heap[right - 1] > heap->heap[LargestIndex-1]){
        LargestIndex = right;
    }
    
    if (LargestIndex != i) {
        //进行一层的调整
        int temp = heap->heap[i - 1];
        heap->heap[i - 1] = heap->heap[LargestIndex - 1];
        heap->heap[LargestIndex - 1] = temp;
        //对子堆进行调整
        MaxHeapify(heap, LargestIndex);
    }
}

//建立一个堆
void BuildMaxHeap(HEAP* heap){
    int i;
    //heapify the nodes that are not leaves
    for (i = heap->length/2; i > 0; i--) {
        MaxHeapify(heap, i);
    }
}

//实现堆排序
//the root node is always the largest
void HeapSort(HEAP* heap){
    int i;
    for (i = heap->length; i > 1; i--) {
        //exchange the last leaf with the root and then reheapify
        int temp = heap->heap[0];
        heap->heap[0] = heap->heap[heap->heap_size - 1];
        heap->heap[heap->heap_size - 1] = temp;
        //now the largest one is out of the heap, it means the largest one has been sorted.
        heap->heap_size--;
        MaxHeapify(heap, 1);
    }
}

//返回队列中最大的值
int HeapMaxium(HEAP* heap){
    if (heap->heap_size != 0) {
        return heap->heap[0];
    } else {
        //mean there is no element in the priority queue
        return INT32_MIN;
    }
}

//返回并删除最大值
int HeapExtractMax(HEAP* heap){
    int max;
    if (heap->heap_size != 0) {
        max = heap->heap[0];
        heap->heap[0] = heap->heap[heap->heap_size - 1];
        heap->heap_size --;
        MaxHeapify(heap, 1);
        return max;
    }
    else {
        //mean there is no element in the priority queue
        return INT32_MIN;
    }
}

//将队列中某一个元素的值增加
void HeapIncreaseKey(HEAP* heap, int i, int newkey){
    if (newkey <= heap->heap[i-1]) {
        //when the newkey is smaller the heap is still a max heap
        return;
    } else {
        while (i > 1 && (heap->heap[i/2-1] < heap->heap[i-1])) {
            int temp = heap->heap[i-1];
            heap->heap[i-1] = heap->heap[i/2-1];
            heap->heap[i/2-1] = temp;
            i = i/2;
        }
    }
}

//将一个新的元素插入优先队列中
void HeapInsertKey(HEAP* heap, int newkey){
    heap->heap_size ++;
    heap->heap[heap->heap_size - 1] = INT32_MIN;
    HeapIncreaseKey(heap, heap->heap_size, newkey);
}
