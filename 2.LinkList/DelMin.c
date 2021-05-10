/*
4.删除带头结点链表中的最小值。
*/

#include<stdio.h>
#include "./utils/utils.c"


bool Del_Min(LinkList L){
    LNode *p, *pre, *minp, *minpre;
    pre = L;
    p = L->next;
    minpre = L;
    minp = L->next;
    while(p){
        if(p->data < minp->data){
            minpre = pre;
            minp = p;
        }
        pre = p;
        p = p->next;
    }

    // delete min node
    minpre->next = minp->next;
    free(minp);
    return true;
}


int main(){
    LinkList L;
    ElemType minv = 1;
    InitList(&L);
    for(int i = 1; i <= 6; ++i){
        ListInsert(L, i, 2*i+2);
    }
    ListInsert(L, 1, minv);

    printf("List==>");
    PrintList(L);
    printf("Min value==>%d\n", minv);
    Del_Min(L);
    printf("New List==>");
    PrintList(L);
    return 0;
}