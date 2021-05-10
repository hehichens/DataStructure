/*
5.逆置带头结点链表。
*/

#include<stdio.h>
#include "./utils/utils.c"


//遍历节点，依次插入到头结点后面
bool Reverse_Link(LinkList *L){
    LNode *p = (*L)->next, *q;
    (*L)->next = NULL;
    while(p){
        q = p->next;
        p->next = (*L)->next;
        (*L)->next = p;
        p = q;
    }
    return true;
}


int main(){
    LinkList L;
    InitList(&L);
    for(int i = 1; i <= 10; ++i){
        ListInsert(L, i, 2*i);
    }

    printf("List==>");
    PrintList(L);

    Reverse_Link(&L);
    printf("New List==>");
    PrintList(L);
    return 0;
}