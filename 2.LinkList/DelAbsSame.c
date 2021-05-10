/*
23.对于绝对值相等的结点， 仅保留第一次出现的结点而删除其他的结点。

> 用数组A保存访问过的结点，绝对值相同的结点保存在同一位置
>
> - 若该点为0，保留并标记为1
> - 若该点为1，删除。
*/


#include<stdio.h>
#include<string.h>
#include "./utils/utils.c"
#define N 100

ElemType Abs(ElemType e){
    return e > 0?e:-e;
}


bool Del_Abs_Same(LinkList L){
    bool A[N+1];
    memset(A, false, N+1);
    LNode *p = L->next, *pre = L;
    while(p){
        if(!A[Abs(p->data)]){
            A[Abs(p->data)] = true;
            pre = p;
            p = p->next;
        }
        else{
            pre->next = p->next;
            free(p);
            p = pre->next;            
        }
    }
    return true;
}



int main(){
    ElemType S[] = {21, -15, -15, -7, 15};
    LinkList L;
    InitList(&L);
    for(int i = 1; i <= 5; ++i)
        ListInsert(L, i, S[i-1]);
    
    printf("List==>");
    PrintList(L);
    Del_Abs_Same(L);
    printf("New List==>");
    PrintList(L);
    return 0;
}