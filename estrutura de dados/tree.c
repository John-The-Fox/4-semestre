#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node{
	int data;
	Node* left;
	Node* right;
}

struct tree{
	Node*root;
};

Tree *create_tree() {
  printf("Criando nodeva árvore\n");
  Tree *nodeva_tree = (Tree *)malloc(sizeof(Tree));
  nodeva_tree->root = NULL;
  return nodeva_tree;
}
Node *create_node(int value) {
  printf("Criando novo no...\n");
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->right = NULL;
  new_node->left = NULL;
  new_node->data = value;
  return new_node;
}

void insert_node(Node *current_node, Node *new_node) {
  if (current_node->data > new_node->data) {
    if (current_node->left != NULL) {
      insert_node(current_node->left, new_node);
    } else {
      current_node->left = new_node;
    }
  } else if (current_node->data < new_node->data) {
    if (current_node->right != NULL) {
      insert_node(current_node->right, new_node);
    } else {
      current_node->right = new_node;
    }
  } else {
    printf("Valor %d já existe na arvore\n", new_node->data);
  }
}

void tree_insert(Tree *tree, int value) {
  Node *new_node = create_node(value);

  if (tree->root == NULL) {
    printf("Inserindo no de valor %d na raiz\n", value);
    tree->root = new_node;
    return;
  }
  insert_node(tree->root, new_node);
}