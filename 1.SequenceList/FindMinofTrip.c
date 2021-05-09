/*
14.三元组(a, b, c) 的距离D=|a-b| + |b-c| + |c-a|。a, b, c分别在三个升序的数组S1, S2, S3中。

> - D_min = INF
> - i=j=k=0. 
>   1. 计算A[i], B[j], C[k] 的距离D
>   2. 若D<D_min，则D_min=D
>   3. 将A[i], B[j], C[k]中最小值的下标+1
> - 输出D_min


*/

#include<stdio.h>
#include "./utils/utils.c"

bool isMin(ElemType a, ElemType b, ElemType c){
    if(a < b && a < c) return true;
    return false;
}

ElemType abs(ElemType e){
    return e > 0?e:-e;
}

int Find_Min_of_Trip(SqList *L1, SqList *L2, SqList *L3){
    int i=0, j=0, k=0;
    int a, b, c;
    ElemType D_min = 0x7fffffff;
    while (i < L1->length && j < L2->length && k < L3->length && D_min > 0){
        a = L1->data[i];
        b = L2->data[j];
        c = L3->data[k];
        ElemType D = abs(a-b) + abs(b-c) + abs(c-a);
        if(D < D_min) D_min = D;
        
        if(isMin(a, b, c)) i++;
        else if(isMin(b, a, c)) j++;
        else k++;
    }
    return D_min;
}


int main(){
    SqList L1, L2, L3;
    int x = 5;

    printf("Test 1\n");
    int A[] = {-1, 0, 9};
    int B[] = {-25. -10, 10, 11};
    int C[] = {2, 9, 17, 30, 4};
    InitList(&L1);
    InitList(&L2);
    InitList(&L3);
    for(int i = 1; i <= 3; ++i)
        ListInsert(&L1, i, A[i-1]);
    for(int i = 1; i <= 4; ++i)
        ListInsert(&L2, i, B[i-1]);
    for(int i = 1; i <= 5; ++i)
        ListInsert(&L3, i, C[i-1]);

    int D = Find_Min_of_Trip(&L1, &L2, &L3);
    printf("Min Distance==>%d\n", D);
    
    return 0;
}