/*
21.查找链表上倒数第k个位置的节点（不改变链表）。

方法一

> 求取链表长度为len，返回第len-k个节点

方法二

> - p指针从头结点移动k个位置
> - q指针指向头结点， p、q同时移动


*/


#include<stdio.h>
#include "./utils/utils.c"


ElemType Search_k_1(LinkList L, int k){
    int len = Length(L);
    len -= k;
    LNode *p = L->next;
    while(len--){
        p = p->next;
    }
    return p->data;
}


ElemType Search_k_2(LinkList L, int k){
    LNode *p = L->next, *q = L->next;
    while(k--)
        p = p->next;
    while(p){
        p = p->next;
        q = q->next;
    }
    return q->data;
}



int main(){
    LinkList L;
    int k = 3;
    InitList(&L);
    for(int i = 1; i <= 6; ++i){
        ListInsert(L, i, 2*i);
    }

    printf("List==>");
    PrintList(L);
    printf("k=%d\n", k);

    printf("Method 1\n");
    printf("Result==>%d\n",Search_k_1(L, k));

    printf("Method 2\n");
    printf("Result==>%d\n",Search_k_2(L, k));

    return 0;
}