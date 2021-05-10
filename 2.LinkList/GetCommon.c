/*
14.A和B是两个递增的单链表，从A、B的公共元素中产生C。

> - 值小的指针往后移
> - 两节点相等时，将后面的节点复制到C
*/


#include<stdio.h>
#include<stdlib.h>
#include "./utils/utils.c"


bool Get_Common(LinkList A, LinkList B, LinkList C){
    LNode *pa, *pb, *pc, *p;
    pa = A->next;
    pb = B->next;
    pc = C;
    while(pa && pb){
        if(pa->data < pb->data)
            pa = pa->next;
        else if(pa->data > pb->data)
            pb = pb->next;
        else{
            p = (LNode *)malloc(sizeof(LNode));
            p->data = pa->data;
            pc->next = p;
            pc = p;  

            pa = pa->next;
            pb = pb->next;          
        }
    }

    if(!pa) pa = pb;
    while(pa){
        p = (LNode *)malloc(sizeof(LNode));
        p->data = pa->data;
        pc->next = p;
        pc = p;
        pa = pa->next;
    }

    pc->next = NULL;
    return true;
}


int main(){
    LinkList L1, L2, L;
    InitList(&L1);
    InitList(&L2);
    InitList(&L);
    for(int i = 1; i <= 6; ++i){
        ListInsert(L1, i, 2*i);
    }
    for(int i = 1; i <= 6; ++i){
        ListInsert(L2, i, 2*i+4);
    }
    ListInsert(L2, 1, 3);
    ListInsert(L2, 1, 3);
    ListInsert(L2, 1, 3);
    ListInsert(L2, 1, 3);
    ListInsert(L2, 1, 3);
    ListInsert(L2, 1, 1);

    printf("List1==>");
    PrintList(L1);
    printf("List2==>");
    PrintList(L2);
    printf("Common List==>");
    Get_Common(L1, L2, L);
    PrintList(L);

    return 0;
}