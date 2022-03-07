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

node_t *
listmiddle(node_t *head) {
  if (!head) return head;
  node_t *slow = head;
  node_t *fast = head;

  while(fast != NULL) {
    fast = fast->nxt;
    if (fast)
			fast = fast->nxt;
    slow = slow->nxt; 
  }
  return slow;
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

int
main() {
	node_t *list = NULL;
	list = insert(list, 1);
	list = insert(list, 2);
	list = insert(list, 3);
	list = insert(list, 4);
	list = insert(list, 5);
	list = insert(list, 6);
	list = insert(list, 7);
	list = insert(list, 8);
	list = insert(list, 9);
	list = insert(list, 10);
	list = insert(list, 11);
	list = insert(list, 11);
	print(list);

	list = listmiddle(list);
  if (list) {
    printf("middle node data %d\n", list->data);
  }
	return 0;
}
