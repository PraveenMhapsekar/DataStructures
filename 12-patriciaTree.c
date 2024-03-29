/* Patricia -> Practical Algorithm To Retieve Information Coded In Aplhanemeric */

#include <stdio.h>
#include <stdlib.h>

typedef struct patriciaTree *patriciaPtr;

typedef struct patriciaTree {
    int bitNumber;
    int data;
    patriciaPtr left;
    patriciaPtr right;
} patricia_t;

/* return true if bitNumber is not set */
int
bit (unsigned int k, int bitNumber) {
  return ((k & (1 << bitNumber)) ? 0 : 1);
}

/* Search the patriciaPtr tree t; return the last node encountered;
  if k is the key in this last node, the search sucessful */
patriciaPtr 
search(patriciaPtr t, unsigned int k) {
	patriciaPtr nxt;
	patriciaPtr cur;

	if (!t) {
	  return NULL;
	}

	cur = t;
	
	nxt = t->left;

	while (nxt && (nxt->bitNumber > cur->bitNumber)) {
		cur = nxt;   
		/* if bitNumber differ move right or move left */
		nxt = bit(k, nxt->bitNumber) ? nxt->right : nxt->left;
	}

	return nxt;
}

void 
insert(patriciaPtr *t, int element) 
{
	patriciaPtr current, parent, last, newNode;
	int i;

	if (!(*t)) { /* empty tree */
			*t = malloc(sizeof(patricia_t));
			(*t)->bitNumber = 0;
			(*t)->data = element;
			(*t)->left = *t;
			(*t)->right = NULL;
			return;
	}

	last = search(*t, element);

	if ((element == last->data)) {
			fprintf(stderr, "The key is in the tree. Iteration failed.\n");
			return;
	}

	/* find first bit where element and last->data differ */
	for (i = 1; bit(element, i) == bit(last->data, i); i++);

	current = (*t)->left;
	parent  = *t;

	/* search tree using first i - 1 elements */
	while ((current->bitNumber > parent->bitNumber) && (current->bitNumber < i)) {
		parent = current;
		current = bit(element, current->bitNumber) ? current->right : current->left;
	}

	/*insert element as child of parent */
	newNode = malloc(sizeof(patricia_t));
	newNode->data = element;
	newNode->bitNumber = i;
	newNode->left = bit(element, i) ? current : newNode;
	newNode->right = bit(element, i) ? newNode : current;
	
	if (current == parent->left) {
		parent->left = newNode;
	} else {
		parent->right = newNode;
	}
}

int
main(void) {
	int n;
	patriciaPtr tree = NULL, tree1;
	insert(&tree, 0x01020305);
	insert(&tree, 0x01020304);
	insert(&tree, 0x01020307);
	insert(&tree, 0x01020306);
#if 0
	insert(&tree, 23);
	insert(&tree, 30);
#endif
	n = 0x01020304;

	tree1 = search(tree, n);
	if (!tree1) {
		printf("failed, lookup null\n");
		return 0;
	}

	if (tree1->data == n) {
		printf("succeess\n");
	} else {
		printf("failed\n");
  }

	return 0;
}
