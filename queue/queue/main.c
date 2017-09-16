//
//  main.c
//  queue
//
//  Created by shinxg on 16/09/2017.
//  Copyright © 2017 shinxg. All rights reserved.
//

#include <stdio.h>
#include "queue.h"

int main(int argc, const char * argv[]) {
    //test for functions
	Queue Q = CreatQueue(5);
	ShowQueue(Q);
	printf("%d\n", isEmpty(Q));
	printf("%d\n", isFull(Q));

	Enqueue(10, Q);
	ShowQueue(Q);
	printf("%d\n", isEmpty(Q));
	printf("%d\n", isFull(Q));

	Enqueue(1, Q);
	ShowQueue(Q);
	printf("%d\n", isEmpty(Q));
	printf("%d\n", isFull(Q));

	Enqueue(2, Q);
	ShowQueue(Q);
	printf("%d\n", isEmpty(Q));
	printf("%d\n", isFull(Q));

	Enqueue(3, Q);
	ShowQueue(Q);
	printf("%d\n", isEmpty(Q));
	printf("%d\n", isFull(Q));

	Enqueue(6, Q);
	ShowQueue(Q);
	printf("%d\n", isEmpty(Q));
	printf("%d\n", isFull(Q));

	Enqueue(5, Q);
	ShowQueue(Q);
	printf("%d\n", isEmpty(Q));
	printf("%d\n", isFull(Q));

	Dequeue(Q);
	ShowQueue(Q);
	printf("%d\n", isEmpty(Q));
	printf("%d\n", isFull(Q));

	MakeEmpty(Q);
	ShowQueue(Q);
	printf("%d\n", isEmpty(Q));
	printf("%d\n", isFull(Q));

	Dequeue(Q);
	ShowQueue(Q);
	printf("%d\n", isEmpty(Q));
	printf("%d\n", isFull(Q));
    return 0;
}
