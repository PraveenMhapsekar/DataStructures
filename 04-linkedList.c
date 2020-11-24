#include <stdio.h>
#include <stdlib.h>

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
delete(node_t **Head, int data) {
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
int delete(node_t **head, int data) {
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

void
reverse(node_t **head) {
  node_t *cur;
  node_t *nxt;
  node_t *pre;

  if (*head == NULL) return;

  cur = *head;
  nxt = cur->nxt;
  pre = NULL;

  while (nxt) {
    cur->nxt = pre;
    pre      = cur;
    cur      = nxt;
    nxt      = nxt->nxt;

  }

  cur->nxt = pre;
   *head = cur;
   return;
}

#if 0
void
reverse(node_t **head) {
	printf("%s\n", __func__);
	node_t *cur = NULL;
	node_t *pre = NULL;
	node_t *nxt = NULL;

	if (*head == NULL) 
			return;    

	cur = *head;    // head of the list
	nxt = cur->nxt; // head next

	while(nxt) {
		cur->nxt = pre;  // connect cur to previous
		pre = cur;       // now, cur becomes previous for next iteration
		cur = nxt;       // keep moving cur and nxt pointers on origional list
		nxt = nxt->nxt;  // keep moving cur and nxt pointers on origional list
	}

	cur->nxt = pre; // connect last cur node to pre
	*head = cur;    // return cur (last node)
	return;
}
#endif
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

#if 0
void 
reversepair(node_t **head) {
	printf("%s\n", __func__);
	node_t *cur = *head;
	node_t *prv = *head;
	node_t *tmp = NULL;
	node_t *tmp2 = NULL;
	*head = cur->nxt;  

	if (*head == NULL) {
		return;
	}

	while (cur && cur->nxt) {
		tmp = cur->nxt;
		tmp2 = tmp->nxt;
		prv->nxt = tmp;
		tmp->nxt = cur;
		cur->nxt = tmp2;
		if (cur) {
			prv = cur;
			cur = cur->nxt;
		}
	}
}
#endif
void 
oddeven(node_t *head) {
	printf("%s\n", __func__);

	if (head == NULL) {
		printf("%s, odd\n", __func__);
		return;
	}
 
	while (head && head->nxt) {
		head = head->nxt->nxt;
	}
 
	if (!head) {
		printf("%s, even\n", __func__);
  }	else { /* head exists but head->next is NULL */
		printf("%s, odd\n", __func__);
  }

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
	insert(&list, 6);
	insert(&list, 7);
	insert(&list, 8);
	print(list);

	reverse(&list);
	print(list);

	//myreverse(&list);
	print(list);

#if 0
	insert(&list, 5);
	insert(&list, 5);
	insert(&list, 5);
	insert(&list, 5);
	insert(&list, 5);
	print(list);
#endif
#if 0
  // reverse(&list);
  // print(list);
	//oddeven(list);
	delete(&list, 5);
  // print(list);

  // delete(&list, 1);
	print(list);
	reverse(&list);
	print(list);
	oddeven(list);

#endif
	reversepair(&list);
	print(list);
	delete(&list, 4);
	print(list);
	delete(&list, 2);
	print(list);
	delete(&list, 3);
	print(list);

	print(list);
	return 0;
}
