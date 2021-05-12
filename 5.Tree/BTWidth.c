/*
14.求二叉树宽度

> 采用层次遍历的思想，count统计当前层结点数，count >max则更新max，last指针指向当前层最右的结点。
*/


#include<stdio.h>
#include "./utils/utils.c"

int BT_Width(BiTree T){
    Queue Q; InitQueue(&Q);
    BiTree p = T, last = T;
    int max=0, count=0;
    EnQueue(&Q, p);
    while(!QueueEmpty(Q)){
        DeQueue(&Q, &p);
        count++;
        if(p == last){
            if(max < count) max = count;
            
            if(p->rchild) last = p->rchild;
            else last = p->lchild;

            count = 0;
        }
        if(p->lchild) EnQueue(&Q, p->lchild);
        if(p->rchild) EnQueue(&Q, p->rchild);
    }
    return max;
}


int main(){
    FILE *fp;
    BiTree T;
    fp = fopen("data.txt", "r");
    InitBiTree(&T);
    CreateBiTree(fp, &T);
    PrintTree(T);

    int width = BT_Width(T);
    printf("Width==>%d\n", width);
    return 0;
}