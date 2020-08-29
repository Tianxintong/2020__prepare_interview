#ifndef __PUBLIC_H_
#define __PUBLIC_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct BinaryTreeNode
{
	int data;
	struct BinaryTreeNode* parent;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}bstNode;
typedef bstNode*  DataType;
#define bool_t int
#define length 100






#endif