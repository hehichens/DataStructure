/*
5.【掌握】采用非递归的方法计算树的高度。

> - level记录当前所在层数
>
> - last指向当前层最右结点
> - 层次遍历完出队时与last对比，相等则level++，last指向下层最右结点
*/


#include<stdio.h>
#include "./utils/utils.c"



int BT_Depth(BiTree T){
    BiTree last = T, p = T;
    int level = 0;
    Queue Q; InitQueue(&Q);
    EnQueue(&Q, p);
    while(!QueueEmpty(Q)){
        DeQueue(&Q, &p);
        if(p == last){
            level++;
            if(p->rchild) last = p->rchild;
            else last = p->lchild;
        }
        if(p->lchild) EnQueue(&Q, p->lchild);
        if(p->rchild) EnQueue(&Q, p->rchild);

    }
    return level;
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

    int depth = BT_Depth(T);
    printf("Depth=%d\n", depth);
    return 0;
}