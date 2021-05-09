#include "utils.h"


/*base function*/
//init function
bool InitList(LinkList *L){
    (*L) = (LNode *)malloc(sizeof(LNode));
    (*L)->next = NULL;
    return true;
}


//get length
int Length(LinkList L){
    LNode *p = L->next;
    int count = 0;
    while (p){
        count++;
        p = p->next;
    }
    return count;
}



//get data
LNode *GetElem(LinkList L, int i){
    if(i == 0) return L;

    int j = 1;
    LNode *p = L->next;
    while(p && j < i){
        p = p->next;
        j++;
    }
    return p;
}


//find data
int LocateElem(LinkList L, ElemType e){
    LNode *p = L->next;
    int count = 1;
    while(p!=NULL && p->data != e){
         p = p->next;
         count++;
    }
    return count; 
}


// insert data
bool ListInsert(LinkList L, int i, ElemType e){
    LNode *p = GetElem(L, i-1);
    LNode *s;
    s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}


//delete data
bool ListDelete(LinkList L, int i, int *e){
    LNode *p, *q;
    p = GetElem(L, i-1);
    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    return true;
}


//print data
bool PrintList(LinkList L){
    LNode *p = L->next;
    while(p){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    return true;
}


//wheater list is empty
bool Empty(LinkList L){
    return (L->next == NULL)?true:false;
}


// clear all the data
bool ClearList(LinkList *L){
    LNode *p, *q;
    if(!L) return false;

    p = (*L)->next;
    while(p){
        q = p;
        p = p->next;
        free(q);
    }
    (*L)->next = NULL;
    return true;
}


//destroy the link list
bool DestroyList(LinkList *L){
    LNode *p, *q;
    p = (*L);
    while(p){
        q = p;
        p = p->next;
        free(q);
    }
    return true;
}

