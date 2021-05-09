/*
1. 从顺序表删除最小元素（假设唯一）并返回该值，空出的位置由最后一个元素填补。
*/

#include<stdio.h>
#include "./utils/utils.c"


bool Del_Min(SqList *L, ElemType *value){
    if(!L->length)
        return false;

    int min = 0;
    for(int i = 1; i < L->length; ++i){
        if(L->data[min] > L->data[i])
            min = i;
    }
    *value = L->data[min];
    L->data[min] = L->data[--L->length];
    return true;
}

int main(){
    SqList L;
    InitList(&L);
    for(int i = 1; i <= 6; ++i)
        ListInsert(&L, i, 2*i);

    printf("List==>");
    PrintList(L);

    int value;
    Del_Min(&L, &value);
    printf("Delete Number==>%d\n", value);
    printf("New List==>");
    PrintList(L);
    return 0;
}