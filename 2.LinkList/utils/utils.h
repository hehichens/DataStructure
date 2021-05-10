/*
utils
edit by hichens
*/

#include<stdlib.h>
#include<stdio.h>
#define ElemType int
#define bool short
#define true 1
#define false 0


typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;



/*base function*/
//init function
bool InitList(LinkList *L);

//get length
int Length(LinkList L);

//get data
LNode *GetElem(LinkList L, int i);

//find data
int LocateElem(LinkList L, ElemType e);

// insert data
bool ListInsert(LinkList L, int i, ElemType e);

//delete data
bool ListDelete(LinkList L, int i, int *e);

//print data
bool PrintList(LinkList L);

//print data if link has not head
bool ShowList(LinkList L);

//wheater list is empty
bool Empty(LinkList L);

// clear all the data
bool ClearList(LinkList *L);

//destroy the link list
bool DestroyList(LinkList *L);