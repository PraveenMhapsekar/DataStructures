#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *left;
	struct node *right;
} node_t;

node_t *
insert(node_t *tree, int n) {
	node_t *temp;

	if (tree == NULL) {
		fprintf(stderr, "Insert %3d\n", n);
		temp = (node_t *)malloc(sizeof(node_t));
		temp->data = n;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	} else {
		if (n < tree->data) {
      tree->left = insert(tree->left, n);
	 	} else { 
		  tree->right =	insert(tree->right, n);
    }
	}
  return tree;
}

void 
inorder(node_t *tree) {
	if (NULL == tree) 
		return; // Base case

	if (tree->left)
		inorder(tree->left); // Visit left subtree

	printf("%3d ", tree->data); // Visit node

	if (tree->right)
		inorder(tree->right); // Visit right subtree

	return; 
}

int
tree_maxdepth(node_t *tree) {
  int maxleft;
  int maxright;
  
  if (!tree) return 0;
  if (!(tree->left) && !(tree->right)) return 1; 

  maxleft = (tree_maxdepth(tree->left));
  maxright = (tree_maxdepth(tree->right));

  if (maxleft > maxright) 
    return maxleft + 1;
  else 
		return maxright + 1;
}

int
tree_mindepth(node_t *tree) {
  int minleft;
  int minright;
  
  if (!tree) return 0;
  if (!(tree->left) && !(tree->right)) return 1; 

	minleft = (tree_mindepth(tree->left));
	minright = (tree_mindepth(tree->right));

  if (minleft < minright)
     return minleft + 1;
  else
     return minright + 1;
}

int 
main() {
	node_t *tree1 = NULL;
	tree1 = insert(tree1, 10);
	tree1 = insert(tree1, 20);
	tree1 = insert(tree1, 15);
	tree1 = insert(tree1, 13);
	tree1 = insert(tree1, 3);
	tree1 = insert(tree1, 5);
	tree1 = insert(tree1, 17);
	tree1 = insert(tree1, 113);

  printf("inorder recursive:\n"); 
  inorder(tree1);
  printf("\n");
  printf("max depth of BST is %d\n", tree_maxdepth(tree1)); 
  printf("\n");
  printf("min depth of BST is %d\n", tree_mindepth(tree1)); 
  printf("\n");
  return 0;
}
