/*
11.对于值为x的结点，删除以它为根的子树并释放对应空间。

> - 层次遍历找到值为x的结点
> - 递归的删除以x为根的树
*/


#include<stdio.h>
#include "./utils/utils.c"


void Del_Tree(BiTree T){
    if(T->lchild) Del_Tree(T->lchild);
    if(T->rchild) Del_Tree(T->rchild);
    free(T);
}


void Del_x(BiTree T, ElemType x){
    Queue Q; InitQueue(&Q);
    BiTree p = T;
    EnQueue(&Q, p);
    while(!QueueEmpty(Q)){
        DeQueue(&Q, &p);
        if(p->lchild){
            if(p->lchild->data == x){
                Del_Tree(p->lchild);
                p->lchild = NULL;
            }
            else
                EnQueue(&Q, p->lchild);
        }
        if(p->rchild){
            if(p->rchild->data == x){
                Del_Tree(p->rchild);
                p->rchild = NULL;
            }
            else
            EnQueue(&Q, p->rchild);
        }
    }
}


int main(){
    FILE *fp;
    BiTree T;
    fp = fopen("data.txt", "r");
    InitBiTree(&T);
    CreateBiTree(fp, &T);
    PrintTree(T);

    ElemType x = 'E';
    Del_x(T, x);

    PrintTree(T);
    return 0;

}