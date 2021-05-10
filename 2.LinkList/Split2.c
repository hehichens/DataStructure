/*
11.C={a1, b1, a2, b2, ..., an, bn}为线性表，拆分得到两个线性表，A={a1, a2, ..., an}，B={b1, b2, ..., bn}。

> 同10，B采用头插法
*/


#include<stdio.h>
#include "./utils/utils.c"


bool Split_List_2(LinkList L1, LinkList L2){
    LNode *p1 = L1->next, *pre;
    int i = 1;
    while(p1){
        if(i%2){
            pre = p1;
            p1 = p1->next;
        }
        else{
            pre->next = p1->next;
            p1->next = L2->next;
            L2->next = p1;
            p1 = pre->next;
        }
        i++;
    }
    return true;
}


int main(){
    LinkList L1, L2;
    InitList(&L1);
    InitList(&L2);
    for(int i = 1; i <= 12; ++i){
        ListInsert(L1, i, i);
    }

    printf("List1==>");
    PrintList(L1);
    Split_List_2(L1, L2);
    printf("After Process...\n");
    printf("List1==>");
    PrintList(L1);
    printf("List2==>");
    PrintList(L2);
    return 0;
}