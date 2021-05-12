/*
10.求先序遍历中第k个值
使用栈求现需遍历，并且计数
*/


#include<stdio.h>
#include "./utils/utils.c"


//Method 1
BiTree Pre_K(BiTree T, int k){
    Stack S; InitStack(&S);
    BiTree p = T;
    while((p || !StackEmpty(S)) &&k){
        if(p){
            Push(&S, p);
            p = p->lchild;
            k--;
            // if(!k) break;
        }
        else{
            Pop(&S, &p);
            p = p->rchild;
        }
    }
    Pop(&S, &p);
    return p;
}


// Method 2
int i = 1;
ElemType Pre_K_2(BiTree T, int k){
    if(!T) 
        return '#';
    if(i == k)
        return T->data;

    char ch;
    i++;
    ch = Pre_K_2(T->lchild, k);
    if(ch != '#') return ch;
    ch = Pre_K_2(T->rchild, k);
    return ch;
}


int main(){
    FILE *fp;
    BiTree T;
    fp = fopen("data1.txt", "r");
    InitBiTree(&T);
    CreateBiTree(fp, &T);
    PrintTree(T);
    PreOrder2(T);
    printf("\n");

    int k = 4;

    BiTree Node = Pre_K(T, k);
    printf("Node %d==>%c\n", k, Node->data);

    char ch = Pre_K_2(T, k);
    printf("Node %d==>%c\n", k, ch);
    return 0;
}