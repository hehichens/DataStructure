

#include<stdio.h>
#include<stdlib.h>
#include "./utils/utils.c"


int main(){
    LinkList L;
    int e = 4;
    printf("Initialize List...\n");
    InitList(&L);
    printf("Insert data...\n");
    for(int i = 1; i <= 6; ++i){
        ListInsert(L, i, 2*i);
    }

    printf("List==>");
    PrintList(L);

    printf("Get length...\n");
    int len = Length(L);
    printf("Length==>%d\n", len);

    printf("locate data...\n");
    int loc = LocateElem(L, e);
    printf("locate at {%d}\n", loc);

    printf("Get data...\n");
    LNode *p = GetElem(L, 2);
    printf("Get data==>%d\n", p->data);

    printf("delete data...\n");
    int del;
    ListDelete(L, loc, &del);
    printf("Delete Data==>%d\n", del);
    printf("New List==>");
    PrintList(L);

    ClearList(&L);
    bool isEmpty = Empty(L);
    if(isEmpty) printf("Empty!\n");

    DestroyList(&L);

    return 0;
}