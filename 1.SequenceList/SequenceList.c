#include<stdio.h>
#include "./utils/utils.c"


int main(){
    SqList L;
    ElemType e = 4;

    printf("Initialize List...\n");
    InitList(&L);
    
    printf("Insert data...\n");
    for(int i = 1; i <= 6; ++i)
        ListInsert(&L, i, 2*i);

    printf("List==>");
    PrintList(L);

    printf("Get length...\n");
    int len = Length(L);
    printf("Length==>%d\n", len);

    printf("locate data...\n");
    int loc = LocateElem(L, e);
    printf("locate at {%d}\n", loc);

    printf("Get data...\n");
    int elem = GetElem(L, 1);
    printf("Get data==>%d\n", elem);

    printf("delete data...\n");
    int del;
    ListDelete(&L, loc, &del);
    printf("Delete Data==>%d\n", del);
    printf("List==>");
    PrintList(L);

    DestroyList(&L);
    bool isEmpty = Empty(L);
    if(isEmpty) printf("Empty!\n");

    return 0;
}