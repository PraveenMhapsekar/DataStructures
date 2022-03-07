#include <stdio.h>
#include <stdlib.h>
#include <unordered_set>

#define DBG printf("%s:%d\n", __func__, __LINE__);
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

node_t *
reverseeven(node_t *lst) {
  node_t *rlst = NULL;
  node_t *rlst_f = NULL;
  node_t *itr = lst; 
  int cnt = 0;

  if (!lst) return NULL;

  while (itr) {
    if ((cnt % 2) == 0) {
      if (itr->nxt) {
        rlst = insert(rlst, itr->nxt->data);
      }
    }
    cnt++;
    itr = itr->nxt;
  }

  cnt = 0;
  itr = lst;
  while (itr) {
    if ((cnt % 2) == 1) {
      if (rlst) {
				itr->data = rlst->data;
				rlst = rlst->nxt;
      }
    }
    cnt++;
    itr = itr->nxt;
  }

  return lst;
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
	list1 = insert(list1, 7);
	list1 = insert(list1, 8);
	list1 = insert(list1, 9);
	list1 = insert(list1, 10);
	list1 = insert(list1, 11);
	list1 = insert(list1, 12);
	print(list1);
  node_t *node = reverseeven(list1);
  if (node) {
    print(node);
  }

	list2 = insert(list2, 9);
	list2 = insert(list2, 28);
	list2 = insert(list2, 21);
	list2 = insert(list2, 14);
	list2 = insert(list2, 7);
  print(list2);
  node = reverseeven(list2);
  if (node) {
    print(node);
  }

	return 0;
}
