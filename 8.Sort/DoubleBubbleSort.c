/*
2.双向冒泡算法，正反两个方向扫描。
*/

#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include "./utils/utils.c"


void Double_Bubble_Sort(Elemtype *A, int n){ 
    int low = 1, high = n;
    while(low < high){
        for(int i = low+1; i <= high; ++i)
            if(A[i] < A[i-1])
                Swap(A+i, A+i-1);
        high--;
        for(int j = high; j >= low+1; --j)
            if(A[j] < A[j-1])
                Swap(A+j, A+j-1);
        low++;
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
    printf("%20s", "DoubleBubbleSort==>");
    Double_Bubble_Sort(A, n);
    PrintList(A, n);

    return 0;
}