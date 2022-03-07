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
rotate(node_t *lst, int n) {
  int cnt = 0;
  node_t *itr = lst;
   
  while (itr) {
    cnt++;
    itr = itr->nxt;
  }
  
  if (cnt <= n)
    return NULL;
 
  itr = lst;
  cnt = cnt - n - 1; 

  while (cnt) {
    itr = itr->nxt;
    cnt--;
  }

  // copy itr->nxt for later insertion
  node_t *nitr = itr->nxt;
  // terminate itr
  itr->nxt = NULL;

  // insert remaining list back in the original list
  while (nitr) {
    lst = insert(lst, nitr->data);
    node_t *tmp = nitr;
    nitr = nitr->nxt;
    free(tmp);
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

   node_t *node = rotate(list1, 3);
   if (node)
     print(node);

	return 0;
}
