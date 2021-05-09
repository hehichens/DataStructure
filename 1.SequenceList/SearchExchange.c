/*
9.顺序表按递增顺序存储，查找x，若找到，则将其与后继元素互换，否则将其插入表中并且仍使得顺序表递增。
*/

#include<stdio.h>
#include "./utils/utils.c"

bool Search_Exchange(SqList *L, ElemType x){
    int i;
    for(i = 0; i < L->length-1 && x > L->data[i]; ++i);

    if(x == L->data[i])
        swap(&L->data[i], &L->data[i+1]);
    else{
        ListInsert(L, i+1, x);
    }
    return true;
}


int main(){
    SqList L;
    ElemType x;
    printf("Test 1\n");
    x = 4;
    printf("x=%d\n", x);
    InitList(&L);
    for(int i = 1; i <= 6; ++i)
        ListInsert(&L, i, 2*i);

    printf("List==>");
    PrintList(L);

    Search_Exchange(&L, x);
    printf("New List==>");
    PrintList(L);
    
    DestroyList(&L);
    printf("===============================================");

    printf("Test 2\n");
    x = 5;
    printf("x=%d\n", x);
    InitList(&L);
    for(int i = 1; i <= 6; ++i)
        ListInsert(&L, i, 2*i);

    printf("List==>");
    PrintList(L);

    Search_Exchange(&L, x);
    printf("New List==>");
    PrintList(L);

    return 0;
}