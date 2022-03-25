#include <stdio.h>
#include <stdlib.h>
#include <unordered_set>

using namespace std;

typedef struct node {
  int data;
  struct node *nxt;
} node_t;

void
insert (node_t **head, int data) {
	node_t *tmp;

	tmp = (node_t *)malloc(sizeof(node_t));
	if (NULL == tmp) {
		printf("malloc failed\n");
	}

	tmp->data = data; 
	tmp->nxt  = *head;

	*head = tmp;
	return;
}

int 
deleteList(node_t **Head, int data) {
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

#if 0
int deletList(node_t **head, int data) {
    printf("%s\t%d\n", __func__, data);
    node_t *tmp;
    node_t *t; 
    if (*head == NULL) printf("Empty List\n");
    while(*head && (*head)->data == data) {
        tmp = *head;
        *head = (*head)->nxt;
        free(tmp);
    }

    tmp = *head;

    while (tmp && tmp->nxt) {
        if (tmp->nxt->data == data) {
            t = tmp->nxt;
            tmp->nxt = tmp->nxt->nxt; 
            free(t);
        } else {
            tmp = tmp->nxt;
        }
    }

    return 0;
}
#endif

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
	insert(&list, 1);
	insert(&list, 2);
	insert(&list, 3);
	insert(&list, 4);
	insert(&list, 5);
	insert(&list, 5);
	insert(&list, 6);
	insert(&list, 7);
	insert(&list, 8);
	print(list);
  deleteList(&list, 5);
	print(list);

	return 0;
}
