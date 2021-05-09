/*
6.从有序表中删除重复的元素。
*/

#include<stdio.h>
#include "./utils/utils.c"

bool Del_Same(SqList *L){
    int k = 0;
    ElemType flag = L->data[0];
    L->data[k++] = flag;
    for(int i = 1; i < L->length; ++i){
        if(L->data[i] != flag){
            flag = L->data[i];
            L->data[k++] = flag;
        }
    }
    L->length = k;
    return true;
}


int main(){
    SqList L;
    InitList(&L);
    for(int i = 1; i <= 6; ++i)
        ListInsert(&L, i, 2*i);
    ListInsert(&L, 6, 10);
    ListInsert(&L, 7, 10);
    ListInsert(&L, 3, 4);
    ListInsert(&L, 4, 4);
    ListInsert(&L, 5, 4);

    printf("List==>");
    PrintList(L);

    Del_Same(&L);
    printf("New List==>");
    PrintList(L);
    
    return 0;
}