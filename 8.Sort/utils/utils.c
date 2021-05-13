/*
utils
edit by hichens

reference:
    - https://www.runoob.com/w3cnote/ten-sorting-algorithm.html
*/

#include "utils.h"

/*Insert Method*/
void InsertSort(Elemtype *A, int n){
    int i, j;
    for(i = 2; i <= n; ++i){
        if(A[i] < A[i-1]){
            A[0] = A[i];
            for(j=i-1; A[0] < A[j]; --j)
                A[j+1] = A[j];
            A[j+1] = A[0];
        }
    }
}

void BinaryInsertSort(Elemtype *A, int n){
    int i, j, low, high, mid;
    for(i = 2; i <= n; ++i){
        A[0] = A[i];
        low = 1, high = i-1;
        while(low <= high){
            mid = (high + low) / 2;
            if(A[0] < A[mid]) high = mid-1;
            else low = mid+1;
        }
        for(j=i-1; j>high; --j)
            A[j+1] = A[j];
        A[high+1] = A[0];
    }
}


void ShellSort(Elemtype *A, int n){
    int dk, i, j;
    for(dk = n/2; dk > 0; --dk){
        for(i = dk+1; i < n; ++i)
            if(A[i] < A[i-dk]){
                A[0] = A[i];
                for(j=dk; j > 0 && A[0] > A[j]; j-=dk)
                    A[j+dk] = A[0];
            }
    }
}



/*Swap Method*/
void BubbleSort(Elemtype *A, int n){
    for(int i = 1; i <= n-1; ++i){
        for(int j = i+1; j <= n; ++j){
            if(A[i] > A[j])
                Swap(A+i, A+j);
        }
    }
}

void QuickSort(Elemtype *A, int low, int high){
    if(low < high){
        int pivotpos = Partition(A, low, high);
        QuickSort(A, low, pivotpos-1);
        QuickSort(A, pivotpos+1, high);
    }
}

int Partition(Elemtype *A, int low, int high){
    Elemtype pivot = A[low];
    while(low < high){
        while(low < high && A[low] < pivot) ++low;
        A[low] = A[high];
        while(low < high && A[high] < A[low]) --high;
        A[high = A[low]];
    }
    A[low] = pivot;
    return low;
}




/*Select Method*/
void SelectSort(Elemtype *A, int n){
    int i, j, min;
    for(i = 1; i <= n; ++i){
        min = i;
        for(j = i+1; j <= n; ++j)
            if(A[min] > A[j])
                min = j;
        if(min != j){
            Swap(A+min, A+i);
        }
    }
}

void HeapSort(Elemtype *A, int n){
    BuildMaxHeap(A, n);
    for(int i = n; i > 1; --i){
        Swap(A+1, A+i);
        HeadAdjust(A, 1, i-1);
    }
}

void BuildMaxHeap(Elemtype *A, int n){
    for(int i = n/2; i >= 1; --i)
        HeadAdjust(A, i, n);
}

void HeadAdjust(Elemtype *A, int k, int n){
    A[0] = A[k];
    for(int i = 2*k; i <= n; ++i){
        if(i < n && A[i] < A[i+1])
            i++;
        if(A[0] >= A[i]) break;
        else{
            A[k] = A[i];
            k  = i;
        }
    }
    A[k] = A[0];
}



/*Others*/
void MergeSort(Elemtype *A, int low, int high);
void Merge(Elemtype *A, int low, int mid, int high);

void RadixSort(Elemtype *A, int n);

void BucketSort(Elemtype *A, int n);

void CountingSort(Elemtype *A, int n);



/*Utils Function*/
void Swap(Elemtype *m, Elemtype *n){
    int temp = *m;
    *m = *n;
    *n = temp;
}