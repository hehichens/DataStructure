/*
utils
edit by hichens

reference:
    - https://www.runoob.com/w3cnote/ten-sorting-algorithm.html
*/


#ifndef __SEARCH__UTILS__C__
#define __SEARCH__UTILS__C__


#include<stdio.h>
#include<stdlib.h>
#define INFINITY 0x7fffffff
#define Elemtype int
#define bool short
#define true 1
#define false 0

/*Insert Method*/
void InsertSort(Elemtype *A, int n);

void BinaryInsertSort(Elemtype *A, int n);

void ShellSort(Elemtype *A, int n);



/*Swap Method*/
void BubbleSort(Elemtype *A, int n);

void QuickSort(Elemtype *A, int low, int high);
int Partition(Elemtype *A, int low, int high);




/*Select Method*/
void SelectSort(Elemtype *A, int n);

void HeapSort(Elemtype *A, int n);
void BuildMaxHeap(Elemtype *A, int n);
void HeapAdjust(Elemtype *A, int k, int n);



/*Others*/
void MergeSort(Elemtype *A, int low, int high);
void Merge(Elemtype *A, int low, int mid, int high);

void RadixSort(Elemtype *A, int n);

void BucketSort(Elemtype *A, int n);

void CountingSort(Elemtype *A, int n);


/*Utils Function*/
void Swap(Elemtype *m, Elemtype *n);

void PrintList(Elemtype *A, int n);

void CopyList(Elemtype *A, Elemtype *B, int n);

#endif