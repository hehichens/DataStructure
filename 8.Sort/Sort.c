

#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include "./utils/utils.c"


void PrintList(Elemtype *A, int n){
    for(int i = 1; i <= n; ++i){
       printf("%d ", A[i]);
    }
    printf("\n");
}



void GenerateList(Elemtype *A){
    srand((unsigned)time(NULL));
    int n = rand()%4+10;
    A = (Elemtype *)malloc(sizeof(Elemtype)*(n+1));
    for(int i = 1; i <= n; ++i){
        A[i] = rand()%50;
    }
    printf("%20s", "OriginnalList==>");
    PrintList(A, n);
    printf("====================\n");

    printf("%20s", "InsertSort==>");
    InsertSort(A, n);
    PrintList(A, n);

    printf("%20s", "BinaryInsertSort==>");
    BinaryInsertSort(A, n);
    PrintList(A, n);

    printf("%20s", "ShellSort==>");
    ShellSort(A, n);
    PrintList(A, n);

    printf("%20s", "BubbleSort==>");
    BubbleSort(A, n);
    PrintList(A, n);

    printf("%20s", "QuickSort==>");
    QuickSort(A, 1, n);
    PrintList(A, n);

    printf("%20s", "SelectSort==>");
    SelectSort(A, n);
    PrintList(A, n);

    printf("%20s", "HeapSort==>");
    HeapSort(A, n);
    PrintList(A, n);

}



int main(){
    Elemtype *A;
    GenerateList(A);
    return 0;
}