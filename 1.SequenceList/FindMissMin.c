/*13.【真题】找出顺序表中未出现的最小整数。{-5, 3, 2, 3}中为1；{1, 2, 3}中为4。*/

#include<stdio.h>
#include<string.h>
#include "./utils/utils.c"

#define SIZE 100

int Find_Miss_Min(SqList *L){
    int i;
    ElemType *B = (ElemType *)malloc(sizeof(ElemType) * SIZE);
    memset(B, 0, sizeof(ElemType)*SIZE);
    for(i = 0; i < L->length; ++i)
        if(L->data[i] > 0 && L->data[i] < SIZE)
            B[L->data[i]] = 1;

    for(i = 1; i < SIZE; ++i)
        if(!B[i]) break;
    return i;
}


int main(){
    SqList L;
    int miss_min;

    printf("Test 1\n");
    int A[] = {-5, 3, 2, 3};
    InitList(&L);
    for(int i = 1; i <= 4; ++i)
        ListInsert(&L, i, A[i-1]);
    miss_min = Find_Miss_Min(&L);
    printf("Miss Min==>%d\n", miss_min);

    DestroyList(&L);
    printf("=====================================================");

    printf("Test 1\n");
    int B[] = {1, 2, 3};
    InitList(&L);
    for(int i = 1; i <= 4; ++i)
        ListInsert(&L, i, B[i-1]);
    miss_min = Find_Miss_Min(&L);
    printf("Miss Min==>%d\n", miss_min);

    return 0;
}