#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *nxt;
} node_t;

void
add (node_t **head, int data)
{
    node_t *tmp = NULL;
    node_t *cur = NULL;
    tmp = (node_t *)malloc(sizeof(node_t));

    if (NULL == tmp) {
        printf("malloc failed\n");
    }

    tmp->nxt = tmp;
    tmp->data = data; 
    
    if (*head != NULL) {
		cur = *head;
		// Get last node
		while (cur->nxt != *head)     
			cur = cur->nxt;
		// link new node with head
		tmp->nxt = (*head);   
		// link last node to newnode
		cur->nxt =  tmp; 
    }

    // head points to new node
    *head = tmp;
    return;
}

int
delete(node_t **head, int data) {
    node_t *temp;
    node_t *cur;
    node_t *t; 
    
    if (*head == NULL) {
        printf("Empty List\n");
        return;
    }

    // Check if this is only node 
    cur = *head; 
    if (cur->nxt == *head) {
       free(cur);
       *head = NULL;
       return 0;
    }

    // find tail node
    while(cur->nxt != (*head)) {
       cur = cur->nxt;
    }

    while(((*head)->nxt != (*head)) && (*head)->data == data) {
        temp = *head;
        // move head
        *head = (*head)->nxt;
        // tail points to updated head
        cur->nxt = *head;
        // free temp
        free(temp);
    }

    while (temp && temp->nxt && (temp->nxt != *head)) {
        if (temp->nxt->data == data) {
            t = temp->nxt;
            temp->nxt = temp->nxt->nxt; 
            free(t);
        }
        temp = temp->nxt;
    }

    return 0;
}

void print(node_t *head) {
    node_t *cur;
    if (head == NULL) {
        return;
    }

    cur = head;
    do {
        printf("%d ", cur->data);
        cur = cur->nxt;
    } while( cur != head);

    printf("\n");
    return;
}

void reverse(node_t **head)
{
    node_t *cur = NULL;
    node_t *pre = NULL;
    node_t *nxt = NULL;
    
    cur = *head;    // head of the list
    nxt = cur->nxt; // head next

    while(nxt) {
        cur->nxt = pre;  // connect cur to previous
        pre = cur;       // now, cur becomes previous for next iteration

        cur = nxt;       // keep moving cur and nxt pointers on origional list
        nxt = cur->nxt;  // keep moving cur and nxt pointers on origional list
    }

   cur->nxt = pre; // connect last cur node to pre
   *head = cur;    // return cur (last node)
   return;
}

int findloop(node_t *head)
{
    node_t *slow;
    node_t *fast;
    int count = 0;
    int loopfound = 0;
    slow = head;
    fast = head;

    while (fast && slow) {

        if (slow == fast) {
            printf("loop found\n");
            loopfound = 1;
            break;
        }

        if (!fast || !slow) {
            loopfound = 0;
            break;
        }

        fast = fast->nxt;
        if (!fast)
            break;

        fast = fast->nxt;
        slow = slow->nxt;
    }

    if (loopfound) {
        do {
            fast = fast->nxt;
            count++;
        } while (fast != slow);

        printf("%s loop count = %d\n", __func__, count);
    } else {
        printf("\n loop not detected\n");
    }

    return 0;
}

void 
oddeven(node_t *head)
{
    if (head == NULL) {
       printf("%s, odd\n", __func__);
       return;
    }
   
    while (head && head->nxt) {
       head->nxt->nxt;
    }
   
    if (!head) {
       printf("%s, even\n", __func__);
       printf("%s, odd\n", __func__);
    }

    return;
}

int
main(void) 
{
    node_t *list = NULL;
   
    add(&list, 1);
    add(&list, 2);
    add(&list, 3);
    add(&list, 4);
    add(&list, 5);
    add(&list, 6);
    add(&list, 7);
    add(&list, 8);

    print(list);
    findloop(list);

#if 0
   delete(&list, 2);
   print(list);
   delete(&list, 1);
   print(list);
   delete(&list, 4);
   print(list);
   delete(&list, 2);
   print(list);
   delete(&list, 3);
   print(list);
#endif
    return 0;
}
