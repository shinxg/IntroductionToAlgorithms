//
//  InsertionSorting.c
//  Sorting
//
//  Created by shinxg on 02/09/2017.
//  Copyright © 2017 shinxg. All rights reserved.
//

#include "InsertionSorting.h"
void InsertionSorting(int * array, int length){
    int j;
    int i;
    for (j = 1; j < length; j++) {
        int key = array[j];
        i = j - 1;
        while (i >= 0 && array[i] > key) {
            array[i+1] = array[i];
            i--;
        }
        array[i+1] = key;
    }
}
