#include <stdio.h>
#include <stdlib.h>
#include <climits>

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

int 
getMin(node_t *root) {
  int lmin;
  int rmin;
  int res; 
  if (!root) return INT_MAX;
  
  lmin = (getMin(root->left));
  rmin = (getMin(root->right));
  res = root->data; 
  if (lmin < res) 
    res = lmin;
  if (rmin < res)
    res = rmin;
  
  return res;
}

int 
getMax(node_t *root) {
  int lmax;
  int rmax;
  int res;
  if (!root) return INT_MIN;
  
  lmax = (getMax(root->left));
  rmax = (getMax(root->right));
  res = root->data; 
  if (lmax > res) 
    res = lmax;
  if (rmax > res)
    res = rmax;
  
  return res;
}

bool 
isValidBST(node_t *root) {
  if (!root) return true;
  
  if (((root->left) && (root->data <= getMax(root->left))) ||
     ((root->right) && (root->data >= getMin(root->right)))) {
    return false;
  }
    
  if (!isValidBST(root->right) || !isValidBST(root->left)) {
    return false;
  }
  
  return true;
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

	printf("inorder tree1\n");
	inorder(tree1);
	printf("\n");

  printf("\nTree is %s BST\n", isValidBST(tree1) == true ? "valid" : "invalid");
  return 0;
}
