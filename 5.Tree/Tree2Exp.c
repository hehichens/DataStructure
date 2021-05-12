/*
20.根据表达式构成的二叉树输出中缀表达式

> - 采用中序遍历
> - 遍历左子树之前加左括号，遍历完右子树之后加右括号
> - 叶结点直接打印

*/


#include<stdio.h>
#include "./utils/utils.c"


void TreeToExp(BiTree T, int deep){
    if(T == NULL) return ;
    else if(T->lchild == NULL && T->rchild == NULL)
        printf("%c", T->data);
    else{
        if(deep) printf("(");
        TreeToExp(T->lchild, deep+1);
        printf("%c", T->data);
        TreeToExp(T->rchild, deep+1);
        if(deep) printf(")");
    }
}



int main(){
    FILE *fp;
    BiTree T;
    fp = fopen("data4.txt", "r");
    InitBiTree(&T);
    CreateBiTree(fp, &T);
    PrintTree(T);
    TreeToExp(T, 0);
    printf("\n");
    return 0;
}