/*
12.打印x结点的所有祖先

> - 采用后序遍历
> - 栈中，x之前的元素都是x的祖先，因此只需要找到x，再依次出栈即可。
*/


#include<stdio.h>
#include "./utils/utils.c"


bool Print_Parents(BiTree T, ElemType x){
    Stack S; InitStack(&S);
    BiTree r=NULL, p=T;
    while(p || !StackEmpty(S)){
        if(p){
            Push(&S, p);
            p = p->lchild;
        }
        else{
            GetTop(S, &p);
            if(p->rchild && p->rchild != r){
                p = p->rchild;
            }
            else{
                Pop(&S, &p);
                // printf("%c ", p->data);
                if(p->data == x)
                break;
                r = p;
                p = NULL;
            }
        }
    }
    while(!StackEmpty(S)){
        Pop(&S, &p);
        printf("%c ", p->data);
    }
    printf("\n");
    return true;
}


int main(){
    FILE *fp;
    BiTree T;
    fp = fopen("data.txt", "r");
    InitBiTree(&T);
    CreateBiTree(fp, &T);
    PrintTree(T);

    ElemType x = 'H';
    Print_Parents(T, x);

    return 0;

}