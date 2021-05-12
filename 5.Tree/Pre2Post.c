/*
15.有一棵满二叉树， 根据先序序列求后序序列。

> - 先序结点的第一个节点为后序结点的最后一个结点
> - 对每一棵子树递归
*/


#include<stdio.h>
#include "./utils/utils.c"


void PreToPost(ElemType *pre, ElemType *post, int l1, int h1, int l2, int h2){
    if(l1 <= h1){
        post[h2] = pre[l1];
        int half = (h1 - l1) / 2;
        PreToPost(pre, post, l1+1, l1+half, l2, l2+half-1);
        PreToPost(pre, post, l1+half+1, h1, l2+half, h2-1);
    }
}



int main(){
    ElemType *pre = "ABCDEFG";
    ElemType *post = (ElemType *)malloc(sizeof(ElemType)*MaxSize);
    PreToPost(pre, post, 0, 6, 0, 6);
    for(int i = 0; i < 7; ++i)
        printf("%c ", post[i]);
    printf("\n");
    return 0;
}