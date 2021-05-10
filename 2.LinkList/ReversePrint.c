/*
3.反向输出带头结点链表的值。
*/


#include<stdio.h>
#include "./utils/utils.c"


void Reverse_Print(LinkList L){
    if(L->next) 
        Reverse_Print(L->next);
    if(L) printf("%d ", L->data);
}

bool R_Print(LinkList L){
    Reverse_Print(L->next);
    printf("\n");
    return true;
}

int main(){
    LinkList L;
    InitList(&L);
    for(int i = 1; i <= 6; ++i){
        ListInsert(L, i, 2*i);
    }

    printf("List==>");
    PrintList(L);

    R_Print(L);

    return 0;
}