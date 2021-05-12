/*
6.二叉树的先序和中序遍历分别保存在A、B数组中， 建立二叉树的二叉链表。

> - 在先序中确定树的根结点
> - 根据根节点将中序划分为左右子树
*/


#include<stdio.h>
#include "./utils/utils.c"

BiTree Pre_In_Create(ElemType *A, ElemType *B, int s1, int l1, int s2, int l2){
    //A PreOrder
    //B InOrder
    BiNode *T = (BiNode *)malloc(sizeof(BiNode));
    int i;
    T->data = A[s1];
    // printf("%c \n", T->data);
    for(i = s2; B[i] != T->data; ++i);
    int lenL = i - s2;
    int lenR = l2 - i;

    if(lenL)
        T->lchild = Pre_In_Create(A, B, s1+1, s1+lenL, s2, s2+lenL-1);
    else
        T->lchild = NULL;
    if(lenR)
        T->rchild = Pre_In_Create(A, B, l1-lenR+1, l1, l2-lenR+1, l2);
    else
        T->rchild = NULL;
    return T;
}


int main(){
    ElemType *A = "ABDGEHICFJ";
    ElemType *B = "GDBHEIAFJC";

    BiTree T = Pre_In_Create(A, B, 0, 9, 0, 9);
    printf("===Tree Overall===\n");
    PrintTree(T);
    printf("==================\n");
    return 0;
}