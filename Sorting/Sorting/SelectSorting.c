//
//  SelectSorting.c
//  Sorting
//
//  Created by shinxg on 02/09/2017.
//  Copyright © 2017 shinxg. All rights reserved.
//

#include "SelectSorting.h"
void SelectSorting(int * array, int length){
    int minIndex;
    int i;
    for (i = 0; i<length; i++) {
        minIndex = i;
        int j = i + 1;
        while (j < length) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
            j++;
        }
        int temp = array[minIndex];
        array[minIndex] = array[i];
        array[i] = temp;
    }
}
