/*
2.将顺序表逆置，空间复杂度要求O(1)。
*/

#include<stdio.h>
#include "./utils/utils.c"

bool ReverseList(SqList *L){
    if(!L->length)
        return false;

    for(int i=0, j=L->length-1; i < j; ++i,--j){
        swap(&L->data[i], &L->data[j]);
    }
    return true;
}

int main(){
    SqList L;
    InitList(&L);
    for(int i = 1; i <= 6; ++i)
        ListInsert(&L, i, 2*i);

    printf("List==>");
    PrintList(L);

    ReverseList(&L);
    printf("New List==>");
    PrintList(L);
    
    return 0;
}