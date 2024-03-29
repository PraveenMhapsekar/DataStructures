#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

typedef struct node *nodePtr;

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node_t;

nodePtr findMinTree (nodePtr root);
nodePtr findMaxTree (nodePtr root);

void
insert(node_t **tree, int n) {
	nodePtr temp;

	if (*tree == NULL) {
		fprintf(stderr, "Insert %3d\n", n);
		temp = (nodePtr )malloc(sizeof(node_t));
		temp->data = n;
		temp->left = NULL;
		temp->right = NULL;
		*tree = temp;
	} else {
		if (n < (*tree)->data) {
			insert(&(*tree)->left, n);
		} else { 
			insert(&(*tree)->right, n);
    }
	}
}
#if 0
void
delete(node_t **root, int n) {
	nodePtr temp;

	if (root == NULL)
	  printf("Data not found\n");
	else if (n < (*root)->data)
		delete(&((*root)->left), n);
	else if (n > (*root)->data)
		delete((&(*root)->right), n);
	else { /// current node is node tobe deleted
		if ((*root)->left && (*root)->right) {
      // both left and right child exit
      // Delete from Left  subtree
      //   find max of left subtree and swap it
      //   call delete in left subtree
			temp = findMaxTree((*root)->left);
			(*root)->data = temp->data;
			delete((&(*root)->left), (*root)->data);
		} else {
      // either only left subtree or right subtree exist
			temp = *root;
			if ((*root)->left) {
				*root = (*root)->left;
			} else if ((*root)->right) {
				*root = (*root)->right;
			} else {
				*root = NULL;
      }

			free(temp);
		}
	}
}
#endif
// Find leftmost child
nodePtr
findMinTree (node_t *root) {
  while (root->left)
    root = root->left;

  return(root);   
}

// find rightmost child
nodePtr
findMaxTree (node_t *root) {
	while (root->right)
		root = root->right;

	return(root);
}

void 
postorder(nodePtr tree) {
	if (NULL == tree) 
		return; //basecase

	if (tree->right)
		postorder(tree->right);   // Visit right subtree

	if(tree->left) 
		postorder(tree->left);   // Visit left subtree

	printf("%3d ", tree->data);   // Visit node
}

void
preorder(nodePtr tree) {
	if (NULL == tree)
	  return;  //basecase

	printf("%3d ", tree->data);   // Visit node

	if (tree->left)  
		postorder(tree->left);    // Visit left subtree

	if (tree->right)
		postorder(tree->right);   // Visit right subtree
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
		curr = s.top(); 
		s.pop(); 
		std::cout << curr->data << " ";
    if (curr->right) {
			s.push(curr->right);
    }
		if (curr->left) {
			s.push(curr->left);
		}
  }
}

void 
inorder(nodePtr tree) {
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
  // 	
  while (!s.empty() || curr != NULL) {
    if (curr != NULL) {
			s.push(curr);
			curr = curr->left;
    } else { // current node is NULL
      // pop and print
			curr = s.top(); s.pop(); std::cout << curr->data << " ";
			curr = curr->right;
    }
  }
}

//This is inorder traversal with count
void
kthSmallest(nodePtr tree, int *count, nodePtr *ret) {
	if (!tree) 
		return;

	if (tree->left) 
		kthSmallest(tree->left, count, ret);

	if ((*count) == 0) {
		*ret = tree;
	}

	(*count)--;

	if (tree->right) 
		kthSmallest(tree->right, count, ret);
}

bool
tree_identical(node_t *r1, node_t *r2) {
  if (!r1 && !r2) return true; // both trees are NULL, identcial 

  if (r1 && r2) {  
    // check if both treenode data match; 
    // left subtree and right subtree are identical
		return ((r1->data == r2->data) &&
					 tree_identical(r1->left, r2->left) &&
					 tree_identical(r1->right, r2->right));
  }

  return false;
}

void
bfs(node_t* tree) {
  queue<node *> q;  // create q for node pointer
  if (!tree) return; // if null , return

  q.push(tree);  // push root
  q.push(NULL);  // push level marker

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

int main() {
	nodePtr tree1 = NULL;

	insert(&tree1, 100);
	insert(&tree1, 50);
	insert(&tree1, 200);
	insert(&tree1, 25);
	insert(&tree1, 75);
	insert(&tree1, 350);

  printf("\nTree BFS:\n");
  bfs(tree1);

  printf("level Avg: \n");
  bfs_lvl_avg(tree1);
  return 0;
}
