//
//  main.c
//  Sorting
//
//  Created by shinxg on 02/09/2017.
//  Copyright © 2017 shinxg. All rights reserved.
//

#include <stdio.h>
#include "MergeSorting.h"
#include "InsertionSorting.h"
#include "SelectSorting.h"
void PrintArray(int* array, int length);

int main(int argc, const char * argv[]) {
    // insert code here...
    int array[6] = {5, 2, 4, 6, 1, 3};
    
    MergeSorting(array, 0, 5);
    PrintArray(array, 6);
    SelectSorting(array, 6);
    PrintArray(array, 6);
    InsertionSorting(array, 6);
    PrintArray(array, 6);
    
    return 0;
}

void PrintArray(int* array, int length){
    int i;
    for (i = 0; i<length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
