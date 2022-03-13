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

node_t *first = NULL;
node_t *last = NULL;

void 
inorder_dll(node_t *node) {
	if (node) {
		// left
		inorder_dll(node->left);

		// process node 
		if (!last) {
			// keep the smallest node
			// to close DLL later on
		  last = node;
			first = node;
		} else {
			// link the previous node (last)
			// with the current one (node)
			last->right = node;
			node->left = last;
		  last = node;
		}

		// right
		inorder_dll(node->right);
	}
}

node_t * 
treeToDoublyList(node_t *root) {
	if (!root) return NULL;
	inorder_dll(root);
	// close DLL
	last->right = first;
	first->left = last;
	return first;
}

int 
main() {
	node_t *tree1 = NULL;
  node_t *llptr = NULL;
  node_t *mptr = NULL;

	tree1 = insert(tree1, 10);
	tree1 = insert(tree1, 20);
	tree1 = insert(tree1, 15);
	tree1 = insert(tree1, 13);
	tree1 = insert(tree1, 3);
	tree1 = insert(tree1, 5);
	tree1 = insert(tree1, 17);
	tree1 = insert(tree1, 113);

  llptr = treeToDoublyList(tree1);
  mptr  = llptr;
 
  printf("\nDoubly LL:\n"); 
	printf("%d ", llptr->data);
	llptr = llptr->right;
  while (llptr != mptr) {
    printf("%d ", llptr->data);
    llptr = llptr->right;
  }  
  printf("\n");
  return 0;
}
