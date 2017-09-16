//
//  list.h
//  list
//
//  Created by shinxg on 15/09/2017.
//  Copyright © 2017 shinxg. All rights reserved.
//

#ifndef list_h
#define list_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//definitions
typedef struct node
{
	int element;
	struct node* next;
}NODE;

typedef NODE* PtrToNode;
typedef PtrToNode Position;
typedef PtrToNode LIST;

//functions
LIST MakeEmpty(LIST L);
bool isEmpty(LIST L);
bool isLast(Position P ,LIST T);
Position Find(int element, LIST L);
void Delete(int element, LIST L);
Position FindPrevious(int element, LIST L);
void Insert(int element, LIST L, Position P);
void DeleteList(LIST L);
Position Header(LIST L);
Position First(LIST L);
Position Advance(Position P);
int Retrieve(Position P);
#endif /* list_h */
