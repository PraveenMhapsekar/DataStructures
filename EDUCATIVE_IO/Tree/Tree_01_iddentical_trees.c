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
		temp = (node_t * )malloc(sizeof(node_t));
		temp->data = n;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	} else {
		if (n < tree->data) {
      tree->left =	insert(tree->left, n);
	 	} else { 
		 tree->right =	insert(tree->right, n);
    }
	}
  return tree;
}

void 
inorder(node_t *tree) {
	if (NULL == tree) 
		return;        // Base case

	if (tree->left)
		inorder(tree->left);    // Visit left subtree

	printf("%3d ", tree->data);  // Visit node

	if (tree->right)
		inorder(tree->right);    // Visit right subtree

	return; 
}

bool
tree_identical(node_t *r1, node_t *r2) {
  if (!r1 && !r2) 
    return true; // both trees are NULL, identcial 

  if (r1 && r2) {  
    // check if both treenode data match; 
    // left subtree and right subtree are identical
		return ((r1->data == r2->data) &&
					 tree_identical(r1->left, r2->left) &&
					 tree_identical(r1->right, r2->right));
  }

  return false;
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

	node_t *tree2 = NULL;
	tree2 = insert(tree2, 10);
	tree2 = insert(tree2, 20);
	tree2 = insert(tree2, 15);
	tree2 = insert(tree2, 13);
	tree2 = insert(tree2, 3);
	tree2 = insert(tree2, 5);
	tree2 = insert(tree2, 17);
	tree2 = insert(tree2, 113);

	printf("inorder tree1\n");
	inorder(tree1);
	printf("\n");

	printf("inorder tree2\n");
	inorder(tree2);
	printf("\n");

  if (tree_identical(tree1, tree2)) {
    printf("tree identical\n");
  } else {
    printf("tree not identical\n");
  }

  return 0;
}
