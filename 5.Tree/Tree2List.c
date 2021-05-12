/*
16.把二叉树的叶结点从左到右连成一个单链表。

> 前中后遍历都可以， pre指向上一个叶结点
*/


#include<stdio.h>
#include "./utils/utils.c"


BiNode *head, *pre=NULL;
BiTree TreeToList(BiTree T){
    if(T){
        if(T->lchild == NULL && T->rchild == NULL){
            if(pre==NULL){
                head = T;
                pre = T;
            }
            else{
                pre->rchild = T;
                pre = T;
            }
        }
        TreeToList(T->lchild);
        TreeToList(T->rchild);
        pre->rchild = NULL;
    }
    return head;
}


int main(){
    FILE *fp;
    BiTree T;
    fp = fopen("data.txt", "r");
    InitBiTree(&T);
    CreateBiTree(fp, &T);
    PrintTree(T);

    head = TreeToList(T);

    BiNode *p=head;
    while(p){
        printf("%c ", p->data);
        p = p->rchild;
    }
    printf("\n");
    return 0;
}