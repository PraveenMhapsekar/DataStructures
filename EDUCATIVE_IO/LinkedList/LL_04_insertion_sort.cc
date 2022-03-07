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
deleteDup(node_t *head) {
	node_t *cur = head;
  unordered_set<int> hash_set;

	if (head == NULL) {
		printf("Empty List \n");
  }

  hash_set.insert(cur->data);

  while (cur->nxt) {
    if (hash_set.find(cur->nxt->data) == hash_set.end()) { // by default unordered set will return last element
       // not found. insert
       hash_set.insert(cur->nxt->data);
       cur = cur->nxt;
     } else {
       node_t *tmp = cur->nxt;
       cur->nxt = cur->nxt->nxt;
       free(tmp);
     }
  }

  return head;
}

int 
deletList(node_t **Head, int data) {
	node_t *tHead;
	node_t *tmp;

	if (*Head == NULL) {
		printf("Empty List \n");
	}

	while (*Head && (*Head)->data == data) {
		tmp = *Head;
		*Head = (*Head)->nxt;
		free(tmp);
	}

	tHead = *Head;

	while (tHead && tHead->nxt) {
		if (tHead->nxt->data == data) {
			tmp = tHead->nxt;
			tHead->nxt = tHead->nxt->nxt;
			free(tmp);
		} else {
			tHead = tHead->nxt;
		}
	}

	return 0;
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
reverse(node_t *head) {
  node_t *cur;
  node_t *nxt;
  node_t *pre;

  if (head == NULL) return head;

  cur = head;
  nxt = cur->nxt;
  pre = NULL;

  while (nxt) {
    cur->nxt = pre;
    pre      = cur;
    cur      = nxt;
    nxt      = nxt->nxt;
  }

  cur->nxt = pre;
  
  return cur;
}

void
reversepair(node_t **head) {
	printf("%s\n", __func__);
	node_t *cur = *head;
	node_t *prv = *head;
	node_t *tp1 = NULL;
	node_t *tp2 = NULL;
	*head = cur->nxt;  
  node_t *nxt = NULL;

	if (*head == NULL) {
		return;
	}

  nxt = cur->nxt;
	while (cur && cur->nxt) {
		tp1 = cur->nxt;
		tp2 = cur->nxt->nxt;
		prv->nxt = tp1;

		tp1->nxt = cur;
		cur->nxt = tp2;
		if (cur) {
			prv = cur;
			cur = cur->nxt;
		}
	}
}
int
main() {
	node_t *list = NULL;
	list = insert(list, 1);
	list = insert(list, 2);
	list = insert(list, 3);
	list = insert(list, 8);
	list = insert(list, 4);
	list = insert(list, 5);
	list = insert(list, 6);
	list = insert(list, 7);
	list = insert(list, 8);
	list = insert(list, 8);
	print(list);

	list = reverse(list);
	print(list);

  list = deleteDup(list);
	print(list);
	return 0;
}
