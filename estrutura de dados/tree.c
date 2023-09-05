#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node{
	int data;
	node* left;
	node* right;
}

typedef struct tree{
	node*root;
} Tree;

Tree* criar_tree
