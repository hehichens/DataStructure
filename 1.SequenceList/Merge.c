/*
7.将两个有序顺序表合并为一个有序顺序表。
*/

#include<stdio.h>
#include "./utils/utils.c"

bool MergeList(SqList *L1, SqList *L2, SqList *L){
    int i=0, j=0, k=0;
    while(i < L1->length && j < L2->length){
        if(L1->data[i] < L2->data[j])
            L->data[k++] = L1->data[i++];
        else
            L->data[k++] = L2->data[j++];
    }

    while(i < L1->length){
            L->data[k++] = L1->data[i++];
    }
    while(j < L2->length){
            L->data[k++] = L2->data[j++];
    }
    L->length = k;
    return true;
}

int main(){
    SqList L1, L2, L;
    InitList(&L1);
    InitList(&L2);
    InitList(&L);
    for(int i = 1; i <= 6; ++i)
        ListInsert(&L1, i, 2*i);
    for(int i = 1; i <= 6; ++i)
        ListInsert(&L2, i, 2*i+6);

    printf("List1==>");
    PrintList(L1);
    printf("List2==>");
    PrintList(L2);

    MergeList(&L1, &L2, &L);
    printf("Merge List==>");
    PrintList(L);

    return 0;
}