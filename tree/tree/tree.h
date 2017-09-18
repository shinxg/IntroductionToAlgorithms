//
//  tree.h
//  tree
//
//  Created by shinxg on 16/09/2017.
//  Copyright © 2017 shinxg. All rights reserved.
//

#ifndef tree_h
#define tree_h

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//definition
typedef struct Node {
    int data;
    struct Node* leftchild;
    struct Node* rightchild;
}Node;

typedef Node* ptrNode;
typedef Node* Tree;
typedef Tree* ptrTree;

//functions
void CreateTree(ptrTree ptrT);
void ClearTree(ptrTree ptrT);
bool TreeEmpty(Tree T);
int TreeDepth(Tree T);

ptrNode TreeRoot(Tree T);
ptrNode Find(Tree T, int value);
bool Assign(Tree T, int oldvalue, int newvalue);
ptrNode Parent(Tree T, int value);
ptrNode LeftChild(Tree T, int value);
ptrNode RightChild(Tree T, int value);
LevelorderTraverse
void InsertChild(Tree T, int value, int LR, Tree c);
void DeleteChild(Tree T, int value, int LR);

void PreorderTraverse(Tree T);
void InorderTraverse(Tree T);
void PostorderTraverse(Tree T);
void LevelorderTraverse(Tree T);


#endif /* tree_h */
