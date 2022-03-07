#include <stdio.h>
#include <stdlib.h>
#include <unordered_set>

using namespace std;

typedef struct node {
  int data;
  struct node *nxt;
} node_t;

node_t *
insert (node_t *head, int data) {
	node_t *tmp;

	tmp = (node_t *)malloc(sizeof(node_t));
	if (NULL == tmp) {
		printf("malloc failed\n");
	}

	tmp->data = data; 
	tmp->nxt  = head;

  return tmp;
}

void
print(node_t *head) {
	if (!head) {
		printf("Empty List\n");
	}

	while(head) {
		printf("%d ", head->data);
		head = head->nxt;
	}
	printf("\n");
	return;
}

node_t *
findnthnode(node_t *lst, int n) {
  if (!lst) return NULL;

  node_t *front = lst;
  node_t *back  = lst;

  while (n) {
    if (front) {
      front = front->nxt;
    } else {
      return NULL;
    } 
    n--;
  }

  while (front) {
    front = front->nxt;
    back  = back->nxt;
  }

  return back;
}

int
main() {
	node_t *list1 = NULL;
	node_t *list2 = NULL;
	list1 = insert(list1, 1);
	list1 = insert(list1, 2);
	list1 = insert(list1, 3);
	list1 = insert(list1, 4);
	list1 = insert(list1, 5);
	list1 = insert(list1, 6);
	list1 = insert(list1, 11);
	list1 = insert(list1, 12);
	list1 = insert(list1, 13);
	list1 = insert(list1, 14);
	list1 = insert(list1, 15);
	list1 = insert(list1, 16);
	print(list1);
  int n = 1;
  node_t *node = findnthnode(list1, n);
  if (node)
  printf("%dth node is %d\n", n, node->data);
	return 0;
}
