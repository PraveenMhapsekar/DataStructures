#include <stdio.h>
#include <stdlib.h>
#include <queue>
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
bfs(node_t* tree) {
  queue<node *> q; // create q for node pointer
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
bfs_zigzag(node_t *tree) {
  queue<node *> q; // create q for node pointer
  stack<int> s;
  bool levelDir = true;
  if (!tree) return; // if null , return

  q.push(tree); // push root
  q.push(NULL); // push level marker

  while (!q.empty()) { // iterate over q
		node_t *tmp = q.front(); q.pop(); // pop and print
    if (levelDir == false) {
      cout << tmp->data << " ";
    } else {
      s.push(tmp->data);
    }

		if (tmp->left) q.push(tmp->left); // push left child
		if (tmp->right) q.push(tmp->right); // push right child

		// Level marker processing
		tmp = q.front(); 
		if (tmp == NULL) { // if level marker
		  q.pop(); // pop level marker (NULL ptr)
      if (levelDir == true) {
        // Empty thy stack
        int ssize = s.size();;
        for (int i = 0; i < ssize; i++) {
          cout << s.top() << " ";
          s.pop();
        }
      }

		  cout <<  endl; // print new line indicating new level
      // Change direction
      levelDir = levelDir == true ? false : true;
		  if (!q.empty()) {
			  q.push(NULL); // push new marker
		  }
		}
  }
  cout << endl;
}

/*
            .
           100
          /   \
         50   200
        / \   / \
       25 75 150 350
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
	tree1 = insert(tree1, 150);

  printf("\nTree BFS:\n");
  bfs(tree1);
	printf("\n");

  printf("BFS Zigzag: \n");
  bfs_zigzag(tree1);
	printf("\n");

  return 0;
}
