#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

#if 0
void inorder_iterative(BinaryTree *root) {
  stack<BinaryTree*> s;
  s.push(root);
  while (!s.empty()) {
    BinaryTree *top = s.top();
    if (top != NULL) {
      if (!top->visited) {
        s.push(top->left);
      } else {
        cout << top->data << " ";
        s.pop();
        s.push(top->right);
      }
    } else {
      s.pop();
      if (!s.empty())
        s.top()->visited = true;
    }
  }
}
#endif

nodePtr
LCA (nodePtr tree, nodePtr A, nodePtr B) {
	if (!tree)
		return NULL;
	if ((tree->left) && (tree->right))
		return tree;
	if ((tree == A) || (tree == B))
		return tree;

	if (tree->left)
		LCA(tree->left, A, B);
	if (tree->right)
		LCA(tree->right, A, B);        
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

int main() {
	nodePtr tree1 = NULL;

	insert(&tree1, 10);
	insert(&tree1, 20);
	insert(&tree1, 15);
	insert(&tree1, 13);
	insert(&tree1, 3);
	insert(&tree1, 5);
	insert(&tree1, 17);
	insert(&tree1, 113);

	nodePtr tree2 = NULL;
	insert(&tree2, 10);
	insert(&tree2, 20);
	insert(&tree2, 15);
	insert(&tree2, 13);
	insert(&tree2, 3);
	insert(&tree2, 5);
	insert(&tree2, 17);
	insert(&tree2, 117);

	printf("inorder tree1\n");
	inorder(tree1);
	printf("\n");

	printf("inorder tree2\n");
	inorder(tree2);
	printf("\n");

  if (tree_identical(tree1, tree2))
    printf("tree identical\n");
  else
    printf("tree not identical\n");
  return 0;
}
