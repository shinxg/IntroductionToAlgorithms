//
//  stack.h
//  stack
//
//  Created by shinxg on 15/09/2017.
//  Copyright © 2017 shinxg. All rights reserved.
//

#ifndef stack_h
#define stack_h

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

//struct definition
typedef struct node
{
	int element;
	struct node* next;
}NODE;

typedef NODE* STACK;

//function definition
bool isEmpty(STACK S);
STACK CreateStack(void);
void DisposeStack(STACK S);
void MakeEmpty(STACK S);
void Push(STACK S, int element);
int Top(STACK S);
void Pop(STACK S);

#endif /* stack_h */
