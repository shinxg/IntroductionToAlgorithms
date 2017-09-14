//
//  BucketSorting.c
//  Sorting
//
//  Created by shinxg on 14/09/2017.
//  Copyright © 2017 shinxg. All rights reserved.
//

#include "BucketSorting.h"


//桶排序
void BucketSort(int* array, int n){
    //指针数组
    int* temp[n];
    //另建一个数组来存储每一个指针指向的数组中含有多少个数
    int count[n];

    int i;
    int j;
    int ten_place;
    
    //initialization
    for (i = 0; i<n; i++) {
        temp[i] = NULL;
        count[i] = 0;
    }
    //insert array[i] in temp
    for (i = 0; i < n; i++) {
        ten_place = array[i]/10;
        count[ten_place]++;
        *(temp + ten_place) = Insert(*(temp + ten_place), count[ten_place], array[i]);
    }
    int tempcount = 0;
    for (i = 0; i < n; i++) {
//        printf("%d. ", count[i]);//debug
        for (j = 0; j<count[i]; j++) {
            array[tempcount] = *(*(temp+i)+j);
            tempcount++;
        }
    }
}

//将一个数插入到数组中使得数组仍然为有序的数组
int* Insert(int* list, int count, int number){
    if (count == 1) {
        list = malloc(sizeof(int));
        list[0] = number;
    } else {
        list = realloc(list, sizeof(int)*count);
        int i;
        int j;
        for (i = 0; i<count; i++) {
            if (number < list[i]) {
                j = count - 1;
                while (j > 0) {
                    list[j] = list[j-1];
                    j --;
                }
                list[i] = number;
                break;
            }
        }
        if (i == count) {
            list[count - 1] = number;
        }
    }
    return list;
}
