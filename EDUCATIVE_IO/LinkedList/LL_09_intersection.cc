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

node_t *
findIntersection(node_t *lst1, node_t *lst2) {
  int len1 = 0; 
  int len2 = 0;
  node_t *l1 = lst1;
  node_t *l2 = lst2;
  if ((!l1) || (!l2)) return NULL; 
  
  while (l1) {
    l1 = l1->nxt;
    len1++;
  }

  while (l2) {
    l2 = l2->nxt;
    len2++;
  }

  if (len1 > len2) {
    int len = len1-len2;
    while(len) {
      lst1 = lst1->nxt;
      len--;
    } 
  } else {
    int len = len2-len1;
    while(len) {
      lst2 = lst2->nxt;
      len--;
    } 
  }

  while (lst1 && lst2) {
    if (lst1 == lst2) {
      return lst1;
    }
    lst1 = lst1->nxt;
    lst2 = lst2->nxt;
  }
  return NULL;
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

	list2 = listmiddle(list1);
	list2 = insert(list2, 21);
	list2 = insert(list2, 22);
	list2 = insert(list2, 23);
	list2 = insert(list2, 24);
	list2 = insert(list2, 25);
	list2 = insert(list2, 26);
	list2 = insert(list2, 27);
	list2 = insert(list2, 28);
	list2 = insert(list2, 29);
	print(list2);

  node_t *node = findIntersection(list1, list2);
  if(node)
  printf("intersetcing node is %d\n", node->data);
	return 0;
}
