/*
9. 交换树T中所有的左右子树。
1. 交换T左孩子的左右子树
2. 交换T右孩子的左右子树
3. 交换T的左右子树
*/


#include<stdio.h>
#include "./utils/utils.c"


void Swap_Tree(BiTree T){
    if(T){
        Swap_Tree(T->lchild);
        Swap_Tree(T->rchild);
        BiTree temp = T->lchild;
        T->lchild = T->rchild;
        T->rchild = temp;
    }
}


int main(){
    FILE *fp;
    BiTree T;
    fp = fopen("data.txt", "r");
    InitBiTree(&T);
    CreateBiTree(fp, &T);
    PrintTree(T);

    Swap_Tree(T);
    printf("After Swap...\n");
    PrintTree(T);

    return 0;
}