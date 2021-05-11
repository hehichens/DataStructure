/*
7.判断一个树是不是完全二叉树。
- 采用层次遍历的思想
- 遇到空结点，则查看队列后面是否有*非空结点*，若有则不是完全二叉树。
*/


#include<stdio.h>
#include "./utils/utils.c"


bool Is_Complete_Tree(BiTree T){
    Queue Q; InitQueue(&Q);
    BiTree p;
    p = T;
    EnQueue(&Q, p);
    while(!QueueEmpty(Q)){
        DeQueue(&Q, &p);
        if(p){
            EnQueue(&Q, p->lchild);
            EnQueue(&Q, p->rchild);
        }
        else{
            while(!QueueEmpty(Q)){
                DeQueue(&Q, &p);
                if(p) return false;
            }
        }
    }
    return true;
}


int main(){
    FILE *fp;
    BiTree T;
    // Test 1
    printf("Test 1\n");
    fp = fopen("data.txt", "r");
    // data： ABDG^^^EH^^I^^CF^J^^^
    InitBiTree(&T);
    CreateBiTree(fp, &T);

    PrintTree(T);
    if(Is_Complete_Tree(T)) printf("\n==>Yes!\n");
    else printf("\n==>No!\n");

    printf("============================\n");

    // Test 2
    printf("Test 2\n");
    FILE *fp1 = fopen("data1.txt", "r");
    // data： ABC^^D^^EF^^G^^
    BiTree T1;
    InitBiTree(&T1);
    CreateBiTree(fp1, &T1);

    PrintTree(T1);
    if(Is_Complete_Tree(T1)) printf("\n==>Yes!\n");
    else printf("\n==>No\n");

    return 0;
}