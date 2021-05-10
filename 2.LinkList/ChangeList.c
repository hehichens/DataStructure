/*
25.将单链表L=(a1, a2, a3, ..., a_n-2, a_n-1, a_n) 转化为 L'=(a1, a_n, a2, a_n-1, a3, ..., a_n-2, ...)。

> 1. p指向头结点，q指向中间结点
>  - 找中间，设置两个指针从头指针开始向后指，一个走一步，一个走两步
> 2. 将q之后的链表逆转
> 3. p、q向后指，依次取结点添加
*/


#include<stdio.h>
#include "./utils/utils.c"

bool Change_List(LinkList L){
    LNode *p = L->next, *q = L->next, *r, *s;
    while(q->next){
        p = p->next;
        q = q->next;
        if(q->next) q = q->next;
    }
    q = p->next;
    p->next = NULL;
    // printf("%d\n", p->data);

    // Reverse
    while(q){
        r = q->next;
        q->next = p->next;
        p->next = q;
        q = r;
    }
    s = L->next;
    q = p->next;
    p->next = NULL;

    while(q){
        r = q->next;
        q->next = s->next;
        s->next = q;
        s = q->next;
        q = r;
    }

    return true;
}


int main(){
    LinkList L;
    InitList(&L);
    for(int i = 1; i <= 7; ++i){
        ListInsert(L, i, 2*i);
    }

    PrintList(L);
    Change_List(L);
    PrintList(L);
    return 0;
}