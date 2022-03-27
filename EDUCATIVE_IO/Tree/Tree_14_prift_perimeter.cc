#include <stdio.h>
#include <stdlib.h>
#include <queue>
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
bfs(node_t *tree) {
  queue<node_t *> q; // create q for node pointer
  if (!tree) return; // if null , return

  q.push(tree); // push root
  q.push(NULL); // push level marker

  while (!q.empty()) { // iterate over q
		node_t *tmp = q.front(); q.pop(); // pop and print
		cout << tmp->data << " ";
		if (tmp->left) q.push(tmp->left);  // push left child
		if (tmp->right) q.push(tmp->right); // push right child

		// Level marker processing
		tmp = q.front(); 
		if (tmp == NULL) { // if level marker
		  q.pop(); // pop level marker (NULL ptr)
		  cout << endl; // print new line indicating new level
		  if (!q.empty()) {
			  q.push(NULL); // push new marker
		  }
		}
  }
  cout << endl;
}

void 
printLeaf(node_t *tree) {
  if (!tree) return;
  if ((tree->left == NULL) && (tree->right == NULL)) {
	  printf(" %d ", tree->data);
	} else {
		printLeaf(tree->left);
		printLeaf(tree->right);
	}
  return;
}

void 
printRight(node_t *tree) {
 if (!tree) return;
 tree = tree->right;
 while (tree->right) {
    cout << " " << tree->data;
    tree = tree->right;
  }
}

void 
printLeft(node_t *tree) {
 while(tree->left) {
    cout << " " << tree->data;
    tree = tree->left;
  }
}

void
printTreePerimeter(node_t *tree) {
 
  if (!tree) return;
  printLeft(tree);
  printLeaf(tree);
  printRight(tree);

}

/*
            .
           100
          /   \
        50    200
        / \     \
      25  75    350
*/
int 
main() {
	node_t *tree1 = NULL;

	tree1 = insert(tree1, 100);
	tree1 = insert(tree1, 50);
	tree1 = insert(tree1, 200);
	tree1 = insert(tree1, 25);
	tree1 = insert(tree1, 75);
	tree1 = insert(tree1, 350);

  printf("\nTree inorder:\n");
  inorder(tree1);
  printf("\n");

  printf("\nTree BFS:\n");
  bfs(tree1);
  printf("\n");

  printf("Print Leaf\n");
  printTreePerimeter(tree1);
  printf("\n");
  return 0;
}
