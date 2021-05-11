/*
4.写出自下而上，从右到左的层次遍历算法。

> 利用原来层次遍历的方法，将遍历的结点全部压栈，再全部出栈。
*/


#include<stdio.h>
#include "./utils/utils.c"


bool Intervel_Level(BiTree T){
    Queue Q; InitQueue(&Q);
    Stack S; InitStack(&S);
    BiTree p=T;
    EnQueue(&Q, p);
    while(!QueueEmpty(Q)){
        DeQueue(&Q, &p);
        Push(&S, p);
        if(p->lchild) EnQueue(&Q, p->lchild);
        if(p->rchild) EnQueue(&Q, p->rchild);
    }

    while(!StackEmpty(S)){
        Pop(&S, &p);
        printf("%c ", p->data);
    }
    printf("\n");
    return true;
}


int main(){
    FILE *fp;
    BiTree T;
    fp = fopen("data.txt", "r");
    // data： ABDG^^^EH^^I^^CF^J^^^
    InitBiTree(&T);
    CreateBiTree(fp, &T);
    printf("===Tree Overall===\n");
    PrintTree(T);
    printf("==================\n");

    Intervel_Level(T);
    return 0;
}