/*
17.判断两棵二叉树是否相似。

> - f(T1, T2)=1, if T1 == T2 == NULL;
> - f(T1, T2)=0, if one of them is NULL and another is not NULL;
> - f(T1, T2) = f(T1->lchild, T2->lchild) &&  f(T1->rchild, T2->rchild) , if T1 != NULL and T2 != NULL.
*/


#include<stdio.h>
#include "./utils/utils.c"


bool Similar_Tree(BiTree A, BiTree B){
    if(A == NULL && B == NULL)
        return true;
    else if(A != NULL && B != NULL)
        return Similar_Tree(A->lchild, B->lchild) && Similar_Tree(A->rchild, B->rchild);
    else
        return false;
}


int main(){
    FILE *fp;
    BiTree T1;
    BiTree T2;
    fp = fopen("data1.txt", "r");
    InitBiTree(&T1);
    CreateBiTree(fp, &T1);
    PrintTree(T1);
    fp = fopen("data2.txt", "r");
    InitBiTree(&T2);
    CreateBiTree(fp, &T2);
    PrintTree(T2);

    if(Similar_Tree(T1, T2)) printf("Yes!\n");
    else printf("No!\n");
    return 0;
}