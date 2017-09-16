//
//  queue.c
//  queue
//
//  Created by shinxg on 16/09/2017.
//  Copyright © 2017 shinxg. All rights reserved.
//

#include "queue.h"

bool isEmpty(Queue Q){
	return Q->Size == 0;
}

bool isFull(Queue Q){
	return Q->Size == Q->Capacity;
}

Queue CreatQueue(int MaxElements){
	Queue Q;
	Q = (Queue)malloc(sizeof(Record));
	Q->Capacity = MaxElements;
	Q->Front = 1;
	Q->Rear = 0;
	Q->Size = 0;
	Q->Array = (int*)malloc(sizeof(int) * MaxElements);
	return Q;
}

void DisposeQueue(Queue Q){
	free(Q->Array);
	free(Q);
}

void MakeEmpty(Queue Q){
	Q->Size = 0;
	Q->Front = 1;
	Q->Rear = 0;
}

void Enqueue(int x, Queue Q){
	if (isFull(Q))
	{
		printf("the queue is full\n");
		return;
	} else {
		//in a circle
		Q->Rear = (Q->Rear+1) % Q->Capacity;
		Q->Array[Q->Rear] = x;
		Q->Size ++;
		return;
	}
}

int Front(Queue Q){
	return Q->Front;
}

void Dequeue(Queue Q){
	if (isEmpty(Q))
	{
		printf("the queue is empty\n");
		return;
	} else {
		Q->Size --;
		Q->Front = (Q->Front+1)%Q->Capacity;
		return;
	}
}

int FrontAndDequeue(Queue Q){
	if (isEmpty(Q))
	{
		printf("the queue is empty\n");
		return -1;
	} else {
		Q->Size --;
        int temp = Q->Array[Q->Front];
		Q->Front = (Q->Front+1)%Q->Capacity;
		return temp;
	}
}

void ShowQueue(Queue Q){
	printf("Capacity: %d Front: %d Rear: %d Size: %d\n", Q->Capacity, Q->Front, Q->Rear, Q->Size);
	printf("Elements in Queue:");
	for (int i = 0; i < Q->Size; ++i)
	{		
		printf("%d ", Q->Array[(i+Q->Front)%Q->Capacity]);
	}
	printf("\n");
}

