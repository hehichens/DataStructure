/*
2.删除带头结点单链表L中所有x的节点。
*/

#include<stdio.h>
#include "./utils/utils.c"


bool Del_x_2(LinkList *L, ElemType x){
    LNode *p = (*L)->next;
    LNode *pre = NULL, *q = NULL;
    while(p){
        if(p->data == x){
            q = p;
            p = p->next;
            pre->next = p;
            free(q);
        }
        else{
            pre = p;
            p = p->next;
        }
    }
    return true;
}


int main(){
    LinkList L;
    InitList(&L);
    for(int i = 1; i <= 6; ++i){
        ListInsert(L, i, 2*i);
    }
    ListInsert(L, 2, 4);
    ListInsert(L, 3, 4);

    printf("List==>");
    PrintList(L);

    ElemType x = 4;
    Del_x_2(&L, x);

    printf("x=%d\n", x);
    printf("New List==>");
    PrintList(L);
    return 0;
}