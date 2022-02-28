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
bfs_lvl_avg(node_t* tree) {
  queue<node *> q;  // create q for node pointer
  if (!tree) return; // if null , return
  int levelSum = 0;
  int levelCnt = 0;
  q.push(tree);  // push root
  q.push(NULL);  // push level marker

  while (!q.empty()) { // iterate over q
		node_t *tmp = q.front(); q.pop(); // pop and print
    levelSum += tmp->data;
    levelCnt++;
		if (tmp->left) q.push(tmp->left);  // push left child
		if (tmp->right) q.push(tmp->right); // push right child

		// Level marker processing
		tmp = q.front(); 
		if (tmp == NULL) { // if level marker
		  q.pop(); // pop level marker (NULL ptr)
      levelSum = levelSum / levelCnt;
		  cout << levelSum << endl; // print new line indicating new level
      levelSum = 0;
      levelCnt = 0;
		  if (!q.empty()) {
			  q.push(NULL); // push new marker
		  }
		}
  }
  cout << endl;
}

/*
            |
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

  printf("\nTree BFS:\n");
  bfs(tree1);

	printf("\n");

  return 0;
}
