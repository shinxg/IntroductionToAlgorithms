//
//  list.c
//  list
//
//  Created by shinxg on 15/09/2017.
//  Copyright © 2017 shinxg. All rights reserved.
//

#include "list.h"

LIST MakeEmpty(LIST L){
	PtrToNode ptr = L->next;
	while (ptr != NULL) {
		PtrToNode temp = ptr->next;
		free(ptr);
		ptr = temp;
	}
	return L;
}

bool isEmpty(LIST L){
	return L->next == NULL;
}

bool isLast(Position P, LIST T){
	return P->next == NULL;
}

Position Find(int element, LIST L){
	PtrToNode temp = L->next;
	while(temp != NULL && temp->element != element) {
		temp = temp -> next;
	}
	return temp;
}

void Delete(int element, LIST L){
	PtrToNode p = FindPrevious(element, L);
	if ( !isLast(p, L) ) {
		PtrToNode temp = p->next;
		p->next = temp->next;
		free(temp);
	}
}

Position FindPrevious(int element, LIST L){
	PtrToNode p = L;
	while (p->next != NULL && p->next->element != element) {
		p = p->next;
	}
	//if not found, this funciton will return the last node of the list
	return p;
}

//insert element after position p
void Insert(int element, LIST L, Position P){
	PtrToNode temp = (PtrToNode)malloc(sizeof(NODE));
	temp->element = element;
	temp->next = P->next;
	P->next = temp;
}

void DeleteList(LIST L){
	PtrToNode p = L;
	PtrToNode temp = L->next;
	free(p);
	p = temp;
	while (temp) {
		temp = temp -> next;
		free(p);
		p = temp;
	}
}

Position Header(LIST L){
	return L;
}

Position First(LIST L){
	return L->next;
}

Position Advance(Position P){
	return P->next;
}

int Retrieve(Position P){
	return P->element;
}
