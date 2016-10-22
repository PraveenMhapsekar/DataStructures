#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node_t;

node_t* 
insert(node_t *tree, int n) 
{
    node_t *temp;

    if (tree == NULL) {
	   temp = (node_t *)malloc(sizeof(node_t));
	   temp->data = n;
	   temp->left = NULL;
	   temp->right = NULL;
       return temp; //Base case
    } else {
		if(n < tree->data) {
			tree->left = insert(tree->left, n);
        } else {
			tree->right = insert(tree->right, n);
        }
    }

    return tree;
}

node_t*
findMinTree (node_t *root) {
   node_t *minNode = root;

   while (root) {
      if ((root->data) < (minNode->data)) {
          minNode = root;
      }
      root = root->left;
   }
   return minNode;
}

node_t*
findMaxTree (node_t *root) {
   node_t *maxNode = root;

   while (root) {
      if ((root->data) > (maxNode->data)) {
          maxNode = root;
      }
      root = root->right;
   }
   return maxNode;
}

node_t*
delete(node_t *root, int n)
{
    node_t *temp;

    if (root == NULL)
        printf("Data not found\n");
    else if (n < root->data)
        root->left = delete(root->left, n);
    else if (n > root->data)
        root->right = delete(root->right, n);
    else {
        if (root->left && root->right) {
            temp = findMaxTree(root->left);
            root->data = temp->data;
            root->left = delete(root->left, root->data);
        } else {
            temp = root;
            if (root->left == NULL)
                root = root->right;
            else if (root->right == NULL);
                root = root->left;
            free(temp);
        }
    }
    return root;
}

void 
inorder(node_t *tree) 
{
   if (NULL == tree) 
       return;        // Base case

   if (tree->left)
       inorder(tree->left);    // Visit left subtree

   printf("%d\n", tree->data);  // Visit node

   if (tree->right)
       inorder(tree->right);    // Visit right subtree

   return; 
}

void 
postorder(node_t *tree) 
{
    if (NULL == tree) 
        return; //basecase

    if (tree->right)
        postorder(tree->right);   // Visit right subtree

    if(tree->left) 
        postorder(tree->left);   // Visit left subtree

    printf("%d\n", tree->data);   // Visit node
}

void
preorder(node_t *tree) 
{
    if (NULL == tree)
       return;  //basecase

    printf("%d\n", tree->data);   // Visit node

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

int main() 
{
    node_t *tree = NULL;
    node_t *node;
    int n;

    tree = insert(tree, 10);
    tree = insert(tree, 20);
    tree = insert(tree, 5);
    tree = insert(tree, 13);
    tree = insert(tree, 3);
    tree = insert(tree, 5);
    tree = insert(tree, 113);
    tree = insert(tree, 13);

    node = findMaxTree(tree);
    printf("Max number %d\n", node->data);

    node = findMinTree(tree);
    printf("Min number %d\n", node->data);

    printf("inorder\n");
    inorder(tree);
 
    n = 20;
    printf("Delete %d from tree\n", n);
    tree = delete(tree, n);

    printf("inorder\n");
    inorder(tree);

    printf("Postorder\n");
    postorder(tree);

    printf("Preorder\n");
    preorder(tree);

    return 0;
}
