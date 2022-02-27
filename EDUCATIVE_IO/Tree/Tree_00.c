#include <stdio.h>
#include <stdlib.h>

typedef struct node *nodePtr;

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node_t;

node_t * findMinTree (node_t * root);
node_t * findMaxTree (node_t * root);

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
}

node_t *
delete(node_t *root, int n) {
	node_t *temp;

	if (root == NULL)
	  printf("Data not found\n");
	else if (n < root->data)
		delete(root->left, n);
	else if (n > root->data)
		delete(root->right, n);
	else { // current node is node tobe deleted
		if (root->left && root->right) { // both left and right child exit
      // Delete from Left  subtree
      //   find max of left subtree and swap it
      //   call delete in left subtree
			temp = findMaxTree(root->left);
			root->data = temp->data;
			delete(root->left, root->data);
		} else { // either only left subtree or right subtree exist
			temp = root;
			if (root->left) {
				root = root->left;
			} else if (root->right) {
				root = root->right;
			} else {
				root = NULL;
      }
			free(temp);
		}
	}
}

// Find leftmost child
node_t *
findMinTree (node_t *root) {
  while (root->left)
    root = root->left;

  return(root);   
}

// find rightmost child
node_t *
findMaxTree (node_t *root) {
	while (root->right)
		root = root->right;

	return(root);
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
postorder(node_t *tree) {
	if (NULL == tree) 
		return; //basecase

	if (tree->right)
		postorder(tree->right);   // Visit right subtree

	if(tree->left) 
		postorder(tree->left);   // Visit left subtree

	printf("%3d ", tree->data);   // Visit node
}

void
preorder(node_t *tree) {
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

node_t *
LCA (node_t *tree, node_t *A, node_t *B) {
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
kthSmallest(node_t *tree, int *count, node_t **ret) {
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

int main() {
	node_t *tree = NULL;

	node_t *tree1 = NULL;
	node_t *node, *node1, *lcm;
	int count = 0;
	int n;
	tree = insert(tree, 10);
	tree = insert(tree, 20);
	tree = insert(tree, 15);
	tree = insert(tree, 13);
	tree = insert(tree, 3);
	tree = insert(tree, 5);
	tree = insert(tree, 17);
	tree = insert(tree, 113);

	node = findMaxTree(tree);
	printf("Max number %d\n", node->data);

	node1 = findMinTree(tree);
	printf("Min number %d\n", node1->data);

	printf("inorder\n");
	inorder(tree);
	printf("\n");

	lcm = LCA(tree, node, node1);
	printf("LCA of %d and %d is %d\n", node->data, node1->data, lcm->data);
	n = 20;
	printf("Delete %d from tree\n", n);
	delete(tree, n);

	printf("Postorder\n");
	postorder(tree);
	printf("\n");

	printf("Preorder\n");
	preorder(tree);
	printf("\n");

	printf("inorder\n");
	inorder(tree);
	printf("\n");

	for (n = 0; n < 8; n++) {
			count = n;
			node = NULL;
			kthSmallest(tree, &count, &node);
			if (node)
					printf("kth(%d) smallest number is %3d\n", n, node->data); 
	} 
	return 0;
}
