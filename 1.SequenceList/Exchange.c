/*
8.一维数组A[m+n]存放了两个线性表，将两个顺序表位置互换。
*/

#include<stdio.h>
#include "./utils/utils.c"


bool ReverseList(SqList *L, int m, int n){
    if(m > n) return false;

    for(int i=m, j=n-1; i < j; ++i,--j){
        swap(&L->data[i], &L->data[j]);
    }
    return true;
}


bool ExchangeList(SqList *L, int m){
    ReverseList(L, 0, L->length);
    ReverseList(L, 0, m);
    ReverseList(L, m, L->length);
    return true;
}


int main(){
    SqList L;
    InitList(&L);
    int m = 6;
    int n = 4;
    int i = 1;
    for(; i <= m; ++i)
        ListInsert(&L, i, 2*i);
    for(; i <= m+n; ++i)
        ListInsert(&L, i, 2*i);

    printf("List==>");
    PrintList(L);

    ExchangeList(&L, m);
    printf("m=%d, n=%d\n", m, n);
    printf("New List==>");
    PrintList(L);
    return 0;
}