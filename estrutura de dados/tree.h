typedef struct tree Tree;

Tree* create_tree();
void insert(Tree* tree,int value);
int binary_src(Tree *tree, int value);
void print_pre_order(Tree *tree);
