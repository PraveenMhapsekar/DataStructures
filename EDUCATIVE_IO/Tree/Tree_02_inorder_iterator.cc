#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <iostream>

using namespace std;

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

void 
inorder_iterative(node_t *root) {
  // create empty stack
  std::stack<node_t*> s;
  // start from the root
  node_t *curr = root;

  while (!s.empty() || curr != NULL) {
    if (curr != NULL) {
			s.push(curr);
			curr = curr->left;
    } else { // current node is NULL
      // pop and print
			curr = s.top(); s.pop(); 
      std::cout << curr->data << " ";
			curr = curr->right;
    }
  }
}

void 
preorder_iterative(node_t *root) {
  // create empty stack
  std::stack<node_t*> s;
  // start from the root
  node_t *curr = root;
  // 	
  s.push(curr);
  while (!s.empty()) {
		curr = s.top(); s.pop();
		std::cout << curr->data << " ";

    if (curr->right) {
			s.push(curr->right);
    }

		if (curr->left) {
			s.push(curr->left);
		}
  }
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

	printf("inorder iterative tree2\n");
	inorder_iterative(tree1);
	printf("\n");

  return 0;
}
