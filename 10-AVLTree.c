#include <stdio.h>
#include <stdlib.h>

#define TRUE  1
#define FALSE 0

typedef struct {
    int key;
} element_t;

typedef struct treeNode *treePointer_t;

struct treeNode {
    element_t     data;
    treePointer_t left;
    treePointer_t right;
    short         bf;
} treeNode_t;

void 
leftRotation(treePointer_t *parent, int *unbalanced)
{
    treePointer_t grandChild, child;
    child = (*parent)->left;

    if (!child)
        return;

    if (child->bf == 1) {
        /* LL rotation */
        (*parent)->left = child->right;
        child->right    = *parent;
        (*parent)->bf   =  0;
        *parent         = child;
    } else {
        /* LR rotation */
        /* Right subtree of children is grandChild */
        grandChild = child->right;
        if (!grandChild)
            return;
        /* Child right is now grandChild left */
        child->right      = grandChild->left;
        (*parent)->left   = grandChild->right;
        grandChild->left  = child;
        grandChild->right = *parent;
        /* Adjust grandchild balance factor */
        /* Now grandChild being new root/parent,
           maintan the fornula bf(Parent) = bf(leftChild) - bf(rightChild) */
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
rightRotation(treePointer_t *parent, int *unbalanced) 
{
    treePointer_t grandChild, child;
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
        child->left       = grandChild->right;
        (*parent)->right  = grandChild->left;
        grandChild->right = child;
        grandChild->left  = *parent;
        /* Now grandChild being new root/parent, maintan the fornula bf(Parent) = bf(leftChild) - bf(rightChild) */
        switch (grandChild->bf) {
            case 1: 
                  (*parent)->bf = 1;
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

/*
   Insert key in the AVL tree and  balance tree accordingly.
*/
void
avlInsert(treePointer_t *parent, element_t x, int *unbalanced)
{
    if (!*parent) { /* Insert element_t into null tree */
        *unbalanced = TRUE;
        *parent = malloc(sizeof(treeNode_t));
        (*parent)->left = (*parent)->right = NULL;
        (*parent)->bf   = 0;
        (*parent)->data = x;
    } else if (x.key < (*parent)->data.key) {
        /* Insert new node in left subtree */
        avlInsert(&(*parent)->left, x, unbalanced);
        if (*unbalanced) {
            /* left subtree is grown bigger, adjust balance */
            switch ((*parent)->bf) {
                case -1 :
                          (*parent)->bf = 0;
                          *unbalanced = FALSE;
                          break;
                case  0 :
                          (*parent)->bf = 1;
                          break;
                case  1 :
                          leftRotation(parent, unbalanced);
            }
        }
    } else if (x.key > (*parent)->data.key) {
        /* insert new node in right subtree */
        avlInsert(&(*parent)->right, x, unbalanced);
        if (*unbalanced) {
            /* right branch may have grown bigger, adjust balance */
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
        /* Key is present in the tree */
        *unbalanced = FALSE;
        printf("The key is already in the tree\n");
    }
}

void 
inorder(treePointer_t tree) 
{
    if (NULL == tree) 
       return; // Base case

    if (tree->left)
       inorder(tree->left); // Visit left subtree

    printf("%d ", tree->data.key); // Visit node

    if (tree->right)
       inorder(tree->right); // Visit right subtree

    return; 
}

int
main (void) 
{
    int ub = 0; /* Unbalanced Factor */
    element_t data;
    treePointer_t tree = NULL;

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

    printf("Inorder\n");
    inorder(tree);
    printf("\n");
 
    return 0;
}
