/*
5.找出数组中第k小的元素
方法一
> 构建小顶堆，依次取k个元素。
方法二
> 使用计数排序的思想，但是不需要计数排序这么多的空间
*/


#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include "./utils/utils.c"


void Adjust(Elemtype *A, int k, int n){
    A[0] = A[k];
    for(int i=2*k; i <= n; ++i){
        if(i<n && A[i] > A[i+1])
            i++;

        if(A[i] >= A[0]) break;
        else{
            A[k] = A[i];
            k = i;
        }
    }
    A[k] = A[0];
}

void BuildMinHeap(Elemtype *A, int n){
    for(int i = n/2; i >= 1; --i)
        Adjust(A, i, n);
}


ElemType Min_k_1(Elemtype *A, int k, int n){
    BuildMinHeap(A, n);
    for(int i = 1; i <= k; ++i)
        Adjust(A, i, n);
    return A[k];
}


ElemType Min_k_2(ElemType *A, int k, int n){
    int i;
    for(i = 0; i <= MaxSize/2; ++i)
        B[i] = 0;
    for(i = 0; i <= n; ++i)
        B[A[i]]++;

    for(i = 0; i <= MaxSize/2 && k; ++i)
        while(B[i] && k){
            B[i]--;
            k--;
        }
    return i-1;
}


ElemType Min_k_3(ElemType *A, int k, int low, int high){
    int pivot=A[low];
    int l = low, h = high;
    while(low < high){
        printf("%d-%d\n", low, high);
        printf("%d-%d-%d\n", A[low], pivot, A[high]);
        // break;
        while(A[high] >= pivot && low < high) high--;
        printf("%d-%d\n", low, high);
        A[low] = A[high];   
        while(A[low] <= pivot && low < high) low++;
        printf("%d-%d\n", low, high);
        A[high] = A[low];
    }
    A[low] = pivot;
    if(low == k)
        return A[low];
    else if(low < k)
        return Min_k_3(A, k, l, low-1);
    else
        return Min_k_3(A, k, high+1, h);
}


int main(){
    srand((unsigned)time(NULL));
    int n = rand()%4+10;
    Elemtype *A;
    int k = 4;
    A = (Elemtype *)malloc(sizeof(Elemtype)*(n+1));
    for(int i = 1; i <= n; ++i){
        A[i] = rand()%50;
    }

    printf("%20s", "OriginnalList==>");
    PrintList(A, n);
    printf("%20s", "HeapSort==>");
    HeapSort(A, n);
    PrintList(A, n);
    printf("Min_%d==>%d\n",k, Min_k_1(A, k, n));
    printf("Min_%d==>%d\n",k, Min_k_2(A, k, n));
    printf("Min_%d==>%d\n",k, Min_k_3(A, k, 1, n));
    return 0;
}