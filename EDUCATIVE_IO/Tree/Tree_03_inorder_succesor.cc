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
  stack<node_t *> stk;

  // start from the root
  node_t *cur = root;

  while (!stk.empty() || cur != NULL) {
    if (cur != NULL) {
      // traverse left till bottom
			stk.push(cur);
			cur = cur->left;
    } else { // curent node is NULL
      // pop and print
			cur = stk.top(); stk.pop(); 
      cout << cur->data << " ";
			cur = cur->right;
    }
  }
}

node_t *
treeMin(node_t *root) {
  if (!root) return nullptr;
  while (root->left != nullptr) {
	  root = root->left;
  }
  cout << "min " << endl;
  return root;
}

node_t *
inOrderSuccesor(node_t *root, int N) {
  node_t *successor = nullptr;
  if (root == nullptr) return nullptr;

  while (root != nullptr) {
    if (root->data < N) {
      root = root->right;
    } else if (root->data > N) {
      successor = root;
      root = root->left;
    } else { // root->data == N
      if (root->right != nullptr) {
        successor = treeMin(root->right);
        return successor;
      }
      break;
    }
    if (root == nullptr) return nullptr;
   }
   return successor;
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

//	printf("inorder iterative tree2\n");
//	inorder_iterative(tree1);
//	printf("\n");

  node_t *tmp =  inOrderSuccesor(tree1, 17);
  if (tmp != nullptr) {
    cout << "inorder successor of 17 is " << tmp->data << endl;
  } else {
    cout << "inorder successor is -1" << endl;
  }

   
  return 0;
}
