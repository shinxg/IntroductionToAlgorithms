//
//  main.c
//  MaxSubArray
//
//  Created by shinxg on 03/09/2017.
//  Copyright © 2017 shinxg. All rights reserved.
//

#include <stdio.h>
#include "MaxSubArray.h"

int main(int argc, const char * argv[]) {
    int array[16] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    SUBARRAY* final;
    final = FindMaxiumSubArray(array, 0, 15);
    printf("%d__%d__%d\n", final->left, final->right, final->sum);
    return 0;
}
