/*
13.将两个递增有序的线性表合并为一个递减有序的线性表。

> 设置两个指针p1, p2，比较p1, p2
>
> - 若p1 <= p2，则将p1头插到L
> - 若p1 > p2，则将p2头插到L
*/


#include<stdio.h>
#include "./utils/utils.c"


bool Move(LinkList L1, LinkList L2){
    /*Move the first node of L1 and insert it to L2 with head.*/
    LNode *r = L1->next;
    L1->next = L1->next->next;
    r->next = L2->next;
    L2->next = r;
    return true;
}

bool MergeList(LinkList L1, LinkList L2, LinkList L){
    while(L1->next && L2->next){
        if(L1->next->data <= L2->next->data)
            Move(L1, L);
        else
            Move(L2, L);
    }
    if(L1->next == NULL){
        while(L2->next)
            Move(L2, L);
    }
    else{
        while(L1->next)
            Move(L1, L);
    }
    free(L1);
    free(L2);
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
        ListInsert(L2, i, 2*i+7);
    }

    printf("List1==>");
    PrintList(L1);
    printf("List2==>");
    PrintList(L2);
    MergeList(L1, L2, L);
    printf("Merge List==>");
    PrintList(L);
    return 0;
}