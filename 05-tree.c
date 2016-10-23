#include <stdio.h>
#include <stdlib.h>

typedef struct node *nodePtr;

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node_t;

nodePtr findMinTree (nodePtr root);
nodePtr findMaxTree (nodePtr root);

void
insert(nodePtr *tree, int n) 
{
    nodePtr temp;

    if (*tree == NULL) {
	   temp = (nodePtr )malloc(sizeof(node_t));
	   temp->data = n;
	   temp->left = NULL;
	   temp->right = NULL;
       *tree = temp;
    } else {
		if(n < (*tree)->data) 
			insert(&(*tree)->left, n);
        else 
			insert(&(*tree)->right, n);
    }
}

void
delete(nodePtr *root, int n)
{
    nodePtr temp;

    if (root == NULL)
        printf("Data not found\n");
    else if (n < (*root)->data)
        delete(&((*root)->left), n);
    else if (n > (*root)->data)
        delete((&(*root)->right), n);
    else {
        if ((*root)->left && (*root)->right) {
            temp = findMaxTree((*root)->left);
            (*root)->data = temp->data;
            delete((&(*root)->left), (*root)->data);
        } else {
            temp = *root;
            if ((*root)->left == NULL)
                *root = (*root)->right;
            else if ((*root)->right == NULL);
                *root = (*root)->left;
            free(temp);
        }
    }
}

nodePtr
findMinTree (nodePtr root) 
{
   nodePtr minNode = root;

   while (root) {
      if ((root->data) < (minNode->data)) {
          minNode = root;
      }
      root = root->left;
   }
   return minNode;
}

nodePtr
findMaxTree (nodePtr root) 
{
   nodePtr maxNode = root;

   while (root) {
      if ((root->data) > (maxNode->data)) {
          maxNode = root;
      }
      root = root->right;
   }
   return maxNode;
}

void 
inorder(nodePtr tree) 
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
postorder(nodePtr tree) 
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
preorder(nodePtr tree) 
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
    nodePtr tree = NULL;
    nodePtr node;
    int n;

    insert(&tree, 10);
    insert(&tree, 20);
    insert(&tree, 5);
    insert(&tree, 13);
    insert(&tree, 3);
    insert(&tree, 5);
    insert(&tree, 113);
    insert(&tree, 13);

    node = findMaxTree(tree);
    printf("Max number %d\n", node->data);

    node = findMinTree(tree);
    printf("Min number %d\n", node->data);

    printf("inorder\n");
    inorder(tree);
 
    n = 20;
    printf("Delete %d from tree\n", n);
    delete(&tree, n);

    printf("inorder\n");
    inorder(tree);

    printf("Postorder\n");
    postorder(tree);

    printf("Preorder\n");
    preorder(tree);

    return 0;
}
