//
//  main.c
//  tree
//
//  Created by shinxg on 16/09/2017.
//  Copyright © 2017 shinxg. All rights reserved.
//

// typedef struct Node {
//     int data;
//     struct Node* leftchild;
//     struct Node* rightchild;
// }Node;

// typedef Node* ptrNode;
// typedef Node* Tree;
// 1 2 3 -1 -1 4 5 -1 6 -1 -1 7 -1 -1 -1

#include <stdio.h>
#include "tree.h"

int main(int argc, const char * argv[]) {
    Tree T = NULL;
    printf("depth: %d\n", TreeDepth(T));
    printf("empty: %d\n", TreeEmpty(T));
    CreateTree(&T);
    printf("%d\n", TreeDepth(T));
    printf("%d\n", TreeEmpty(T));

    char c;
    while((c = getchar())!='\n') {
    	continue;
    }

    printf("depth: %d\n", TreeDepth(T));
    printf("empty: %d\n", TreeEmpty(T));
    PreorderTraverse(T);
    printf("\n");
    InorderTraverse(T);
    printf("\n");
    PostorderTraverse(T);
    printf("\n");

    ptrNode root = TreeRoot(T);
    if (root)
    {
        printf("root: %d\n", root->data);
    }

    root = Find(T, 2);
    if (root)
    {
        printf("root: %d\n", root->data);
    }

    Assign(T, 2, 8);
    PreorderTraverse(T);
    printf("\n");
    InorderTraverse(T);
    printf("\n");
    PostorderTraverse(T);
    printf("\n");

    root = Parent(T, 8);
    if (root)
    {
        printf("Parent for 8: %d\n", root->data);
    }

    root = LeftChild(T, 8);
    if (root)
    {
        printf("leftchild for 8: %d\n", root->data);
    }

    root = RightChild(T, 8);
    if (root)
    {
        printf("rightchild for 8: %d\n", root->data);
    }

    ClearTree(&T);
    printf("depth: %d\n", TreeDepth(T));
    printf("empty: %d\n", TreeEmpty(T));
    return 0;
}
