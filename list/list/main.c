//
//  main.c
//  list
//
//  Created by shinxg on 15/09/2017.
//  Copyright © 2017 shinxg. All rights reserved.
//

#include <stdio.h>
#include "list.h"

int main(int argc, const char * argv[]) {
    LIST L;
    L = (PtrToNode)malloc(sizeof(NODE));
    L->next = NULL;
    printf("%d\n", isEmpty(L));
    
    Insert(1, L, L);
    Insert(2, L, L);
    Insert(3, L, L);
    
    PtrToNode position = Find(3, L);
    printf("%d\n", isLast(position, L));
    
    position = Find(2, L);
    printf("%d\n", isLast(position, L));
    
    position = FindPrevious(2, L);
    printf("%d\n", position->element);
    
    MakeEmpty(L);
    position = Find(2, L);
    printf("%d\n", position);
    
    return 0;
}
