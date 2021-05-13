/*
3.把数组中奇数都移动到偶数前面。

> - 采用快排的思想
> - low从前向后，遇到偶数停止
> - high从后向前，遇到奇数停止
*/


#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include "./utils/utils.c"

void Fast_Move(Elemtype *A, int n){
    int low = 1, high = n;
    while(low < high){
        while(A[low]%2 == 1 && low < high) low++;
        while(A[high]%2 == 0 && low < high) high--;
        printf("%d-%d\n", low, high);
        Swap(A+low, A+high);
        low++;
        high--;
    }
}


int main(){
    srand((unsigned)time(NULL));
    int n = rand()%4+10;
    Elemtype *A;
    A = (Elemtype *)malloc(sizeof(Elemtype)*(n+1));
    for(int i = 1; i <= n; ++i){
        A[i] = rand()%50;
    }

    printf("%20s", "OriginnalList==>");
    PrintList(A, n);
    printf("%20s", "FastMove==>");
    Fast_Move(A, n);
    PrintList(A, n);
}