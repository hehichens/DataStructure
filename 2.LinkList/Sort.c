/*
6.将带有头结点的单链表递增排序。

> 采取直接插入排序，p为工作指针，通过pre指针寻找p节点插入的位置。
*/

#include<stdio.h>
#include "./utils/utils.c"


bool SortLink(LinkList L){
    LNode *p, *pre, *r;
    p = L->next;
    r = p->next;
    p->next = NULL;
    p = r;
    while(p){
        r =p->next;
        pre = L;
        while(pre->next && pre->next->data < p->data)
            pre = pre->next;
        p->next = pre->next;
        pre->next = p;
        p = r;
    }
    return true;
}



int main(){
    LinkList L;
    InitList(&L);
    for(int i = 1; i <= 6; ++i){
        ListInsert(L, i, 20-2*i);
    }

    printf("List==>");
    PrintList(L);

    printf("New List==>");
    PrintList(L);
    return 0;
}