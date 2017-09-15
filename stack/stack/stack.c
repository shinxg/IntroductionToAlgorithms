//
//  stack.c
//  stack
//
//  Created by shinxg on 15/09/2017.
//  Copyright © 2017 shinxg. All rights reserved.
//

#include "stack.h"

bool isEmpty(STACK S){
	return (S->next == NULL);
}

STACK CreateStack(void){
	STACK S;
	S = (STACK) malloc(sizeof(NODE));
	if (S == NULL){
		printf("out of space\n");
		return S;
	} else {
		S->next = NULL;
		MakeEmpty(S);
		return S;
	}
}

void DisposeStack(STACK S){
	free(S);
	return;
}

void MakeEmpty(STACK S){
	if (S == NULL){
		printf("STACK S does not exist\n");
	} else {
		while(!isEmpty(S)){
			Pop(S);
		}
	}
}

void Push(STACK S, int element){
	NODE* temp;
	temp = (NODE*) malloc(sizeof(NODE));
	if (temp == NULL)
	{	
		printf("out of space\n");
		return;
	} else {
		temp->element = element;
		temp->next = S->next;
		S->next = temp;
	}
}

int Top(STACK S){
    if (isEmpty(S)) {
        printf("the stack is empty\n");
        return INT_MIN;
    }
	return S->next->element;
}

void Pop(STACK S){
	NODE* temp;
	if (isEmpty(S))
	{
		printf("the stack is empty\n");
		return;
	} else {
		temp = S->next;
		S->next = temp->next;
		free(temp);
		return;
	}
}




















