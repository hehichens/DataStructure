/*
utils
edit by hichens
*/

#include<stdlib.h>
#include<stdio.h>
#define ElemType int
#define MaxSize 50
#define InitSize 100
#define bool int
#define true 1
#define false 0


// SequenceList with static allocated
/*
typedef struct 
{
    ElemType data[MaxSize];
    int length;
}Sqlist;
*/

// SequenceList with dynamic allocated
//i.e. L.data = (ElemType*)malloc(sizeof(ElemType)*InitSize)
typedef struct utils
{
    ElemType *data;
    int length;
}SqList;


/* base functions */
// init function
bool InitList(SqList *L);

//get length
int Length(SqList L);

//locate data
int LocateElem(SqList L, ElemType e);

//get data
ElemType GetElem(SqList L, int i);

// insert data
bool ListInsert(SqList *L, int i, ElemType e);


// delete data
bool ListDelete(SqList *L, int i, ElemType *e);

//print data
bool PrintList(SqList L);

//wheater list is empty
bool Empty(SqList L);

// clear all the data
bool DestroyList(SqList *L);



/*other function*/
//swap function
bool swap(ElemType *e1, ElemType *e2);
