#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  Tree *my_tree = create_tree();
  insert(my_tree, 7);
  insert(my_tree, 5);
  insert(my_tree, 9);
  insert(my_tree, 3);
  insert(my_tree, 12);
  insert(my_tree, 10);
  insert(my_tree, 13);
  binary_src(my_tree, 3);
  binary_src(my_tree, 8);
  print_pre_order(my_tree);
  
  return 0;
}
