#include <stdio.h>
#include <stdlib.h>

#define TRUE  1
#define FALSE 0

typedef struct {
    int key;
} element;

typedef struct treeNode *treePointer;

struct treeNode {
    element     data;
    treePointer left;
    treePointer right;
    short       bf;
} treeNode;

void 
leftRotation(treePointer *parent, int *unbalanced)
{
    treePointer grandChild, child;
    child = (*parent)->left;

    if (!child)
        return;

    if (child->bf == 1) {
        /* LL rotation */
        (*parent)->left = child->right;
        child->right    = *parent;
        (*parent)->bf   =  0;
        (*parent)       = child;
    } else {
        /* LR rotation */
        grandChild = child->right;
        if (!grandChild)
            return;
        child->right = grandChild->left;
        grandChild->left = child;
        (*parent)->left = grandChild->right;
        grandChild->right = *parent;
        switch (grandChild->bf) {
            case 1: 
                  (*parent)->bf = -1;
                  child->bf = 0;
                  break;
            case 0:
                  (*parent)->bf = 0;
                  child->bf     = 0;
                  break;      
            case -1:
                  (*parent)->bf = 0;
                   child->bf    = 1;
        }
        *parent =  grandChild;     
    }

    (*parent)->bf = 0;
    *unbalanced   = FALSE;
}

void rightRotation(treePointer *parent, int *unbalanced) 
{
    treePointer grandChild, child;
    child = (*parent)->right;

    if (!child)
        return;

    if (child->bf == 1) {
        /* RR rotation */
        (*parent)->right= child->left;
        child->left     = *parent;
        (*parent)->bf   =  0;
        (*parent)       = child;
    } else {
        /* LR rotation */
        grandChild = child->left;
        if (!grandChild)
            return;
        child->left = grandChild->right;
        grandChild->right = child;
        (*parent)->right = grandChild->left;
        grandChild->left = *parent;
        switch (grandChild->bf) {
            case 1: 
                  (*parent)->bf = -1;
                  child->bf = 0;
                  break;
            case 0:
                  (*parent)->bf = 0;
                  child->bf     = 0;
                  break;      
            case -1:
                  (*parent)->bf = 0;
                   child->bf    = 1;
        }
        *parent =  grandChild;     
    }

    (*parent)->bf = 0;
    *unbalanced   = FALSE;
}

void
avlInsert(treePointer *parent, element x, int *unbalanced)
{
    if (!*parent) { /*insert element into null tree */
        *unbalanced = TRUE;
        *parent = malloc(sizeof(treeNode));
        (*parent)->left = (*parent)->right = NULL;
        (*parent)->bf   = 0;
        (*parent)->data = x;
    } else if (x.key < (*parent)->data.key) {
        avlInsert(&(*parent)->left, x, unbalanced);
        if (*unbalanced) {
            /* left branch is grown higer */
            switch ((*parent)->bf) {
                case -1 :
                          (*parent)->bf = 0;
                          *unbalanced = FALSE;
                          break;
                 case 0 :
                          (*parent)->bf = 1;
                          break;
                 case 1 :
                          leftRotation(parent, unbalanced);
            }
        }
    } else if (x.key > (*parent)->data.key) {
        avlInsert(&(*parent)->right, x, unbalanced);
        if (*unbalanced) {
            /* right branch is grown higer */
            switch ((*parent)->bf) {
                case -1 :
                          (*parent)->bf = 0;
                          *unbalanced = FALSE;
                          break;
                 case 0 :
                          (*parent)->bf = 1;
                          break;
                 case 1 :
                          rightRotation(parent, unbalanced);
            }
        }
    } else {
        *unbalanced = FALSE;
        printf("The key is already in the tree\n");
    }
}

void 
inorder(treePointer tree) 
{
   if (NULL == tree) 
       return;        // Base case

   if (tree->left)
       inorder(tree->left);    // Visit left subtree

   printf("%d\n", tree->data.key);  // Visit node

   if (tree->right)
       inorder(tree->right);    // Visit right subtree

   return; 
}

int
main (void) 
{
    int ub = 0; /* Unbalanced Factor */
    element data;
    treePointer tree = NULL;

    data.key = 1;
    avlInsert(&tree, data, &ub);
    data.key = 3;
    avlInsert(&tree, data, &ub);
    data.key = 7;
    avlInsert(&tree, data, &ub);
    data.key = 8;
    avlInsert(&tree, data, &ub);
    data.key = 6;
    avlInsert(&tree, data, &ub);
    data.key = 4;
    avlInsert(&tree, data, &ub);
    data.key = 2;
    avlInsert(&tree, data, &ub);
    data.key = 5;
    avlInsert(&tree, data, &ub);

    printf("inorder\n");
    inorder(tree);
 
    return 0;
}
