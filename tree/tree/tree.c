//
//  tree.c
//  tree
//
//  Created by shinxg on 16/09/2017.
//  Copyright © 2017 shinxg. All rights reserved.
//

#include "tree.h"
void CreateTree(ptrTree ptrT){
	int input;
	scanf("%d", &input);
	if (-1 == input)
	{
		*ptrT = NULL;
	} else {
		(*ptrT) = (ptrNode)malloc(sizeof(Node));
		(*ptrT)->data = input;
		(*ptrT)->leftchild = NULL;
		(*ptrT)->rightchild = NULL;
		CreateTree(&((*ptrT)->leftchild));
		CreateTree(&((*ptrT)->rightchild));
	}
}

void ClearTree(ptrTree ptrT){
	if (NULL == *ptrT)
	{
		return;
	} else {
		ClearTree(&((*ptrT)->leftchild));
		ClearTree(&((*ptrT)->rightchild));
		free(*ptrT);
		//must set T to NULL
		*ptrT = NULL;
		return;
	}
}

bool TreeEmpty(Tree T){
	return (T==NULL);
}

int TreeDepth(Tree T){
	if (T == NULL)
	{
		return 0;
	} else {
		int leftmaxdepth = TreeDepth(T->leftchild);
		int rightmaxdepth = TreeDepth(T->rightchild);
		return ((leftmaxdepth>rightmaxdepth ? leftmaxdepth : rightmaxdepth) + 1);
	}
}

ptrNode TreeRoot(Tree T){
	return T;
}

ptrNode Find(Tree T, int value){
	ptrNode returnnode;
	if (T == NULL)
	{
		return NULL;
	} else {
		if (T->data == value)
		{
			returnnode = T;
		} else {
			returnnode = Find(T->leftchild, value);
			//if not found in the left tree
			if (returnnode == NULL)
			{
				returnnode = Find(T->rightchild, value);
			}
		}
		return returnnode;
	}
}

bool Assign(Tree T, int oldvalue, int newvalue){
	ptrNode node = Find(T, oldvalue);
	if (node != NULL)
	{
		node->data = newvalue;
		return true;	
	} else {
		return false;
	}
}

ptrNode Parent(Tree T, int value){
	if (T == NULL)
	{
		return NULL;
	} else {
		if (T->leftchild->data == value || T->rightchild->data == value)
		{
			return T;
		} else {
			ptrNode parent;
			parent = Parent(T->leftchild, value);
			if (parent == NULL)
			{
				parent = Parent(T->rightchild, value);
			}
			return parent;
		}
	}
}

ptrNode LeftChild(Tree T, int value){
	ptrNode node = Find(T, value);
	if (NULL != node)
	{
		return node->leftchild;
	} else {
		return NULL;
	}
}

ptrNode RightChild(Tree T, int value){
	ptrNode node = Find(T, value);
	if (NULL != node)
	{
		return node->rightchild;
	} else {
		return NULL;
	}
}

//LR: 1--left, 0--right
void InsertChild(Tree T, int value, int LR, Tree c){
	ptrNode node = Find(T, value);
	if (1 == LR)
	{
		if (node != NULL && node->leftchild != NULL)
		{
			ClearTree(&(node->leftchild));
			node->leftchild = c;
		}
	} else {
		if (node != NULL && node->rightchild != NULL)
		{
			ClearTree(&(node->rightchild));
			node->rightchild = c;
		}
	}
}

void DeleteChild(Tree T, int value, int LR){
	ptrNode node = Find(T, value);
	if (node != NULL && 1 == LR)
	{
		ClearTree(&(node->leftchild));
	} else if (node != NULL && 0 == LR){
		ClearTree(&(node->rightchild));
	}
}

void PreorderTraverse(Tree T){
	if (T != NULL)
	{
		printf("%d", T->data);
		PreorderTraverse(T->leftchild);
		PreorderTraverse(T->rightchild);
	}
	return;
}

void InorderTraverse(Tree T){
	if (T != NULL)
	{
		InorderTraverse(T->leftchild);
		printf("%d", T->data);
		InorderTraverse(T->rightchild);
	}
	return;
}

void PostorderTraverse(Tree T){
	if (T != NULL)
	{
		PostorderTraverse(T->leftchild);
		PostorderTraverse(T->rightchild);
		printf("%d", T->data);
	}
	return;
}

void LevelorderTraverse(Tree T){

}
