/*
9.按照递增次序输出单链表各节点的数据，并释放所占空间。

> 1.依次遍历找到最小节点
>
> 2.输出并删除该节点
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
    printf("%d ", minp->data);
    free(minp);
    return true;
}

bool Sort_Print(LinkList L){
    while(L->next)
        Del_Min(L);
    printf("\n");
    return true;
}


int main(){
    LinkList L;
    InitList(&L);
    for(int i = 1; i <= 6; ++i){
        ListInsert(L, i, 20-2*i);
    }

    printf("List==>");
    PrintList(L);
    printf("Sort List==>");
    Sort_Print(L);
    return 0;
}