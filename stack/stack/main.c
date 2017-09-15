//
//  main.c
//  stack
//
//  Created by shinxg on 15/09/2017.
//  Copyright © 2017 shinxg. All rights reserved.
//

#include <stdio.h>
#include "stack.h"

int main(int argc, const char * argv[]) {
    STACK S = CreateStack();
    printf("%d\n", isEmpty(S));
    
    Push(S, 1);
    printf("%d\n", isEmpty(S));
    printf("%d\n", Top(S));
    
    Pop(S);
    printf("%d\n", isEmpty(S));
    
    Push(S, 2);
    printf("%d\n", isEmpty(S));
    printf("%d\n", Top(S));
    
    MakeEmpty(S);
    printf("%d\n", isEmpty(S));
    printf("%d\n", Top(S));
    
    return 0;
}
