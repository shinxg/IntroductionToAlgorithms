//
//  queue.h
//  queue
//
//  Created by shinxg on 16/09/2017.
//  Copyright © 2017 shinxg. All rights reserved.
//

#ifndef queue_h
#define queue_h

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//definitions
typedef struct record
{
	int Capacity;
	int Front;
	int Rear;
	int Size;
	int* Array;
}Record;

typedef Record* Queue;

//functions
bool isEmpty(Queue Q);
bool isFull(Queue Q);
Queue CreatQueue(int MaxElements);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(int x, Queue Q);
int Front(Queue Q);
void Dequeue(Queue Q);
int FrontAndDequeue(Queue Q);
void ShowQueue(Queue Q);

#endif /* queue_h */
