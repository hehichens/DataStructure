/*
12.【真题】整数序列A=(a0, a1, a2,...,an-1)，其中0<=ai<n。
存在a_p1=a_p2=...=a_pm=x且m > m/2(0<=pk<n, 1<=k<=m)，则称x为A的主元素。
如A=(0, 5, 5, 3, 5, 7, 5, 5)中5的个数为5>8/2=4，所以5是主元素。
*/

#include<stdio.h>
#include "./utils/utils.c"

int MarjorityList(SqList *L, ElemType x){
    int count, flag, i;
    flag = L->data[0];
    for(i = 1; i < L->length; ++i){
        if(L->data[i] == flag) count++;
        else{
            if(count) count--;
            else{
                flag = L->data[i];
                count = 1;
            }
        }
    }

    if(count){
        for(i=count=0; i < L->length; ++i)
            if(L->data[i] == x)
                count++;
    }
    if(count > L->length/2) return true;
    else return false;
}

int main(){
    SqList L;
    int x = 5;

    printf("Test 1\n");
    int A[] = {0, 5, 5, 3, 5, 7, 5, 5};
    InitList(&L);
    for(int i = 1; i <= 8; ++i)
        ListInsert(&L, i, A[i-1]);

    if(MarjorityList(&L, x))
        printf("Yes!\n");
    else
        printf("No!\n");

    DestroyList(&L);
    printf("=======================================================\n");

    printf("Test 2\n");
    int B[] = {0, 5, 5, 3, 5, 1, 5, 7};
    InitList(&L);
    for(int i = 1; i <= 8; ++i)
        ListInsert(&L, i, B[i-1]);

    if(MarjorityList(&L, x))
        printf("Yes!\n");
    else
        printf("No!\n");
    
    return 0;
}