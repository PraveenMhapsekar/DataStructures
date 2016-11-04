#include<stdio.h>
#include<stdlib.h>

typedef struct list *listptr_t;

typedef struct list {
     listptr_t nxt;
     listptr_t pre;
     int dat;
} list_t;

void
insert(listptr_t *list, int data)
{

   fprintf(stderr, "insert %d\n", data);
   listptr_t tmp;
   tmp = (listptr_t)malloc(sizeof(list_t));
   tmp->dat = data;
   tmp->nxt = *list;
   tmp->pre = NULL;
   if (tmp->nxt) {
       tmp->nxt->pre = tmp;
   } 
   *list = tmp;
}

void
delete(listptr_t *list, int data)
{
    fprintf(stderr, "delete %d\n", data);
    listptr_t *tl;
    tl = list;
    listptr_t tmp, t;

    if (tl && (*tl)->dat == data) {
        tmp = *tl;
        *tl = (*tl)->nxt;
        if (*tl)
        (*tl)->pre = NULL;
        free(tmp);
    }

    t = (*tl);

    while (t && t->nxt) {
        if (t->nxt->dat == data) {
            tmp = t->nxt;
            t->nxt = t->nxt->nxt;
            if (t->nxt) {
               t->nxt->pre = t;
            }
            free(tmp);
            return;
        } else {
            t = t->nxt;
        }
    }
}

void
print(listptr_t list)
{
    if (!list)
        return;
    while(list) {
        fprintf(stderr, "addr %p data %d nxt %p prev %p\n", list, list->dat, list->nxt, list->pre);
        list = list->nxt;
    }
    fprintf(stderr, "\n");
}

int
main(int argc, char *argv, char **env) 
{
    listptr_t list;

    insert(&list, 10);
    insert(&list, 30);
    insert(&list, 20);
    print(list); 

    delete(&list, 10);
    print(list);

    delete(&list, 20);
    print(list);

    delete(&list, 30);
    print(list);

    insert(&list, 10);
    insert(&list, 30);
    insert(&list, 20);
    print(list); 
    return 0;
}

