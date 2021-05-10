/*
1.用递归实现：删除不带头结点的单链表L中所有值为x的节点。
*/

#include<stdio.h>
#include<stdlib.h>
#include "./utils/utils.c"


void Del_x(LinkList *L, ElemType x){
    if(*L == NULL) return ;

    if((*L)->data == x){
        LNode *p = *L;
        *L = (*L)->next;
        free(p);
        Del_x(L, x);
    }
    else Del_x(&(*L)->next, x);
}



int main(){
    int s[] = {1, 1, 2, 3, 1, 2, 1};
    LinkList L = (LNode *)malloc(sizeof(LNode));
    LNode *p = L;
    p->data = s[0];
    p->next = NULL;
    for(int i = 1; i < 7; ++i){
        LNode *q;
        q = (LNode *)malloc(sizeof(LNode));
        q->data = s[i];;
        q->next = NULL;
        p->next = q;
        p = q;
    }
    ShowList(L);
    Del_x(&L, 1);

    ShowList(L);

    return 0;
}