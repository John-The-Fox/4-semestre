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

int max(int a, int b) { return (a > b) ? a : b; }

int hightCalculation(Node *node) {
  if (node == NULL) {
    return 0;
  }
  int r_hight = hightCalculation(node->right) + 1;
  int l_hight = hightCalculation(node->left) + 1;
  return max(r_hight, l_hight);
}

int balanceCalculation(Node *node) {
  if (node == NULL) {
    return 0;
  }
  return hightCalculation(node->right) - hightCalculation(node->left);
}

void rotate_r(Node *current_node, Tree *tree) {
  Node *current_left = current_node->left;
  Node *current_left_right = current_left->right;

  current_left->right = current_node;
  current_node->left = current_left_right;
  if (current_node == tree->root) {
    tree->root = current_left;
  }
}

void rotate_l(Node *current_node, Tree *tree) {
  Node *current_right = current_node->right;
  Node *current_right_left = current_right->left;

  current_right->left = current_node;
  current_node->right = current_right_left;
  if (current_node == tree->root) {
    tree->root = current_right;
  }
}

Tree *create_tree() {
  printf("Criando nova árvore\n");
  Tree *new_tree = (Tree *)malloc(sizeof(Tree));
  new_tree->root = NULL;
  return new_tree;
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

int balance = balanceCalculation(current_node);

  if (balance == -2) {
    int left_balance = balanceCalculation(current_node->left);
    if (left_balance == -1) {
      printf("Rotação simples para direita\n");
      rotate_r(current_node, tree);
    } else if (left_balance == 1) {
      printf("Rotação dupla para direita\n");
      rotate_l(current_node->left, tree);
      rotate_r(current_node, tree);
    }
  } else if (balance == 2) {
    int right_balance = balanceCalculation(current_node->right);
    if (right_balance == 1) {
      printf("Rotação simples para esquerda\n");
      rotate_l(current_node, tree);
    } else if (right_balance == -1) {
      printf("Rotação dupla para esquerda\n");
      rotate_r(current_node->right, tree);
      rotate_l(current_node, tree);
    }
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

int rec_binary_src(Node *node, int value) {
  if (node == NULL) {
    printf("Valor %d não encontrado\n", value);
    return 0;
  } else if (node->data == value) {
    printf("Valor %d encontrado\n", value);
    return 1;
  } else if (node->data > value) {
    return rec_binary_src(node->left, value);
  } else {
    return rec_binary_src(node->right, value);
  }
}

int busca_binaria(Tree *tree, int value) {
  return rec_binary_src(tree->root, value);
}

void rec_print_pre_order(Node *node) {
  if (node == NULL)
    return;
  printf("%d ", node->data);
  rec_print_pre_order(node->left);
  rec_print_pre_order(node->right);
}

void print_pre_order(Tree *tree) {
  printf("Arvore impressa em pré ordem:\n");
  rec_print_pre_order(tree->root);
}

void rec_print_in_order(Node *node) {
  if (node->left =! NULL)
    rec_print_in_order(node->left); 
  printf("%d ", node->data);
  if (node->right =! NULL) 
    rec_print_in_order(node->right);
  return;
}

void print_in_order(Tree *tree) {
  printf("Arvore impressa em ordem:\n");
  rec_print_in_order(tree->root);
}

void rec_print_post_order(Node *node) {
  if (node->left =! NULL)
    rec_print_post_order(node->left); 
  if (node->right =! NULL) 
    rec_print_post_order(node->right);
  printf("%d ", node->data);
  return;
}

void print_post_order(Tree *tree) {
  printf("Arvore impressa em pós ordem:\n");
  rec_print_post_order(tree->root);
}
