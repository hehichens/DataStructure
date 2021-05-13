

#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include "./utils/utils.c"


void Test_Sort(){
    srand((unsigned)time(NULL));
    int n = rand()%4+10;
    Elemtype *A, *B;
    A = (Elemtype *)malloc(sizeof(Elemtype)*(n+1));
    B = (Elemtype *)malloc(sizeof(Elemtype)*(n+1));
    for(int i = 1; i <= n; ++i){
        A[i] = rand()%50;
    }
    CopyList(B, A, n);
    printf("%20s", "OriginnalList==>");
    PrintList(A, n);
    printf("====================\n");

    printf("%20s", "InsertSort==>");
    InsertSort(A, n);
    PrintList(A, n);

    CopyList(A, B, n);
    printf("%20s", "BinaryInsertSort==>");
    BinaryInsertSort(A, n);
    PrintList(A, n);

    CopyList(A, B, n);
    printf("%20s", "ShellSort==>");
    ShellSort(A, n);
    PrintList(A, n);

    CopyList(A, B, n);
    printf("%20s", "BubbleSort==>");
    BubbleSort(A, n);
    PrintList(A, n);

    // CopyList(A, B, n);
    printf("%20s", "QuickSort==>");
    QuickSort(A, 1, n);
    PrintList(A, n);

    CopyList(A, B, n);
    printf("%20s", "SelectSort==>");
    SelectSort(A, n);
    PrintList(A, n);

    CopyList(A, B, n);
    printf("%20s", "HeapSort==>");
    HeapSort(A, n);
    PrintList(A, n);

    CopyList(A, B, n);
    printf("%20s", "MergeSort==>");
    MergeSort(A, 0, n);
    PrintList(A, n);

    CopyList(A, B, n);
    printf("%20s", "RadixSort==>");
    RadixSort(A, n);
    PrintList(A, n);

    CopyList(A, B, n);
    printf("%20s", "CountingSort==>");
    CountingSort(A, n);
    PrintList(A, n);
}



int main(){
    Test_Sort();
    return 0;
}