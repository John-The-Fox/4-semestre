#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  Tree *my_tree = create_tree();
  inserir(my_tree, 7);
  inserir(my_tree, 5);
  inserir(my_tree, 9);
  inserir(my_tree, 3);
  
  return 0;
}
