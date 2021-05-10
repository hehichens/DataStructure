/*
12.删除有序链表中的重复值。

> 将p与其下一个节点比较
>
> - 若相等则删除该节点
> - 若不相等则p向后指


*/


#include<stdio.h>
#include "./utils/utils.c"


bool Del_Same(LinkList L){
    LNode *p = L, *r;
    while(p->next){
        if(p->data == p->next->data){
            r = p->next;
            p->next = p->next->next;
            free(r);
        }
        else
            p = p->next;
    }
    return true;
}


int main(){
    LinkList L;
    InitList(&L);
    for(int i = 1; i <= 6; ++i){
        ListInsert(L, i, 2*i);
    }
    ListInsert(L, 4, 8);
    ListInsert(L, 4, 8);
    ListInsert(L, 2, 4);
    ListInsert(L, 2, 4);
    ListInsert(L, 2, 4);



    printf("List==>");
    PrintList(L);
    Del_Same(L);
    printf("New List==>");
    PrintList(L);
    return 0;
}