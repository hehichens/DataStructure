/*
8.统计二叉树所有双分支结点的个数
- f(b) = 0 if b = NULL;
- f(b) = f(b->lchild) + f(b->rchild) + 1 if *b has double son nodes;
- f(b) = f(b->lchild) + f(b->rchild) if *b is other nodes.
*/


#include<stdio.h>
#include "./utils/utils.c"

int Dson_Nodes(BiTree b){
    if(b == NULL) 
        return 0;
    else if(b->lchild && b->rchild)
        return Dson_Nodes(b->lchild) + Dson_Nodes(b->rchild) + 1;
    else
        return Dson_Nodes(b->lchild) + Dson_Nodes(b->rchild);
}


int main(){
    FILE *fp;
    BiTree T;
    fp = fopen("data1.txt", "r");
    InitBiTree(&T);
    CreateBiTree(fp, &T);
    PrintTree(T);

    int num = Dson_Nodes(T);
    printf("NOde number==>%d\n", num);
    return 0;
}