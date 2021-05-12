/*
19.计算所有叶结点的带权路径之和。

> - 基于先序遍历
> - 设置全局变量wpl；
> - 如果是叶结点，wpl += deep * p->data
*/

#include<stdio.h>
#include "./utils/utils.c"


int WPL(BiTree T, int deep){
    static int wpl = 0;
    if(T){
        if(T->lchild == NULL && T->rchild == NULL){
            int data = T->data - '0';
            wpl += deep*data;
        }
        WPL(T->lchild, deep+1);
        WPL(T->rchild, deep+1);
    }
    return wpl;
}


int main(){
        FILE *fp;
    BiTree T;
    fp = fopen("data3.txt", "r");
    InitBiTree(&T);
    CreateBiTree(fp, &T);
    PrintTree(T);
    int wpl = WPL(T, 0);
    printf("WPL=%d\n", wpl);
    return 0;
}