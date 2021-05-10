

#include<stdio.h>
#include "./utils/utils.c"


int main(){
    Stack S;
    printf("Initialize Stack...\n");
    InitStack(&S);
    printf("\nPush data...\n");
    for(int i = 1; i <= 6; ++i){
        printf("Push==>%d\n", 2*i);
        Push(&S, 2*i);
    }

    printf("\nGet top data...\n");
    ElemType e;
    GetTop(S, &e);
    printf("Top Data==>%d\n", e);


    printf("\nPop data...\n");
    ElemType x;
    Pop(&S, &x);
    printf("Pop==>%d\n", x);
    Pop(&S, &x);
    printf("Pop==>%d\n", x);


    bool isEmpty = StackEmpty(S);
    if(isEmpty) printf("Empty!\n");
    else printf("Not Empty!\n");

    Pop(&S, &x);
    printf("Pop==>%d\n", x);
    Pop(&S, &x);
    printf("Pop==>%d\n", x);
    Pop(&S, &x);
    printf("Pop==>%d\n", x);
    Pop(&S, &x);
    printf("Pop==>%d\n", x);
    isEmpty = StackEmpty(S);
    if(isEmpty) printf("Empty!\n");

    return 0;
}