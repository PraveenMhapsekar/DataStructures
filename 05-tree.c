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
<<<<<<< HEAD
       fprintf(stderr, "Insert %3d\n", n);
=======
>>>>>>> 7afd4cae90cfc1e317f6f260a9f4a587bad3ec3c
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
<<<<<<< HEAD
            if ((*root)->left)
                *root = (*root)->left;
            else if ((*root)->right)
                *root = (*root)->right;
            else 
                *root = NULL;
=======
            if ((*root)->left == NULL)
                *root = (*root)->right;
            else if ((*root)->right == NULL);
                *root = (*root)->left;
>>>>>>> 7afd4cae90cfc1e317f6f260a9f4a587bad3ec3c
            free(temp);
        }
    }
}

nodePtr
findMinTree (nodePtr root) 
{
<<<<<<< HEAD
#if 0
=======
>>>>>>> 7afd4cae90cfc1e317f6f260a9f4a587bad3ec3c
   nodePtr minNode = root;

   while (root) {
      if ((root->data) < (minNode->data)) {
          minNode = root;
      }
      root = root->left;
   }
   return minNode;
<<<<<<< HEAD
#endif
   while (root->left)
       root = root->left;

   return(root);   
=======
>>>>>>> 7afd4cae90cfc1e317f6f260a9f4a587bad3ec3c
}

nodePtr
findMaxTree (nodePtr root) 
{
<<<<<<< HEAD
#if 0    
=======
>>>>>>> 7afd4cae90cfc1e317f6f260a9f4a587bad3ec3c
   nodePtr maxNode = root;

   while (root) {
      if ((root->data) > (maxNode->data)) {
          maxNode = root;
      }
      root = root->right;
   }
   return maxNode;
<<<<<<< HEAD
#endif   
   while (root->right)
       root = root->right;
   return(root);
=======
>>>>>>> 7afd4cae90cfc1e317f6f260a9f4a587bad3ec3c
}

void 
inorder(nodePtr tree) 
{
   if (NULL == tree) 
       return;        // Base case

   if (tree->left)
       inorder(tree->left);    // Visit left subtree

<<<<<<< HEAD
   printf("%3d ", tree->data);  // Visit node
=======
   printf("%d\n", tree->data);  // Visit node
>>>>>>> 7afd4cae90cfc1e317f6f260a9f4a587bad3ec3c

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

<<<<<<< HEAD
    printf("%3d ", tree->data);   // Visit node
=======
    printf("%d\n", tree->data);   // Visit node
>>>>>>> 7afd4cae90cfc1e317f6f260a9f4a587bad3ec3c
}

void
preorder(nodePtr tree) 
{
    if (NULL == tree)
       return;  //basecase

<<<<<<< HEAD
    printf("%3d ", tree->data);   // Visit node
=======
    printf("%d\n", tree->data);   // Visit node
>>>>>>> 7afd4cae90cfc1e317f6f260a9f4a587bad3ec3c

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

<<<<<<< HEAD
nodePtr
LCA (nodePtr tree, nodePtr A, nodePtr B) 
{
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

void
kthSmallest(nodePtr tree, int *count, nodePtr *ret) 
{

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

int main() 
{
    nodePtr tree = NULL;

    nodePtr tree1 = NULL;
    nodePtr node, node1, lcm;
    int count = 0;
=======
int main() 
{
    nodePtr tree = NULL;
    nodePtr node;
>>>>>>> 7afd4cae90cfc1e317f6f260a9f4a587bad3ec3c
    int n;

    insert(&tree, 10);
    insert(&tree, 20);
<<<<<<< HEAD
    insert(&tree, 15);
    insert(&tree, 13);
    insert(&tree, 3);
    insert(&tree, 5);
    insert(&tree, 17);
    insert(&tree, 113);
=======
    insert(&tree, 5);
    insert(&tree, 13);
    insert(&tree, 3);
    insert(&tree, 5);
    insert(&tree, 113);
    insert(&tree, 13);
>>>>>>> 7afd4cae90cfc1e317f6f260a9f4a587bad3ec3c

    node = findMaxTree(tree);
    printf("Max number %d\n", node->data);

<<<<<<< HEAD
    node1 = findMinTree(tree);
    printf("Min number %d\n", node1->data);

    printf("inorder\n");
    inorder(tree);
    printf("\n");

    lcm = LCA(tree, node, node1);
    printf("LCA of %d and %d is %d\n", node->data, node1->data, lcm->data);
=======
    node = findMinTree(tree);
    printf("Min number %d\n", node->data);

    printf("inorder\n");
    inorder(tree);
 
>>>>>>> 7afd4cae90cfc1e317f6f260a9f4a587bad3ec3c
    n = 20;
    printf("Delete %d from tree\n", n);
    delete(&tree, n);

<<<<<<< HEAD
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
=======
    printf("inorder\n");
    inorder(tree);

    printf("Postorder\n");
    postorder(tree);

    printf("Preorder\n");
    preorder(tree);

>>>>>>> 7afd4cae90cfc1e317f6f260a9f4a587bad3ec3c
    return 0;
}
