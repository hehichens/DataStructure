/*
13.找到p、q最近的公共祖先结点r。

> - 采用后序遍历
> - 将p、q的祖先分别保存到栈中
> - 使用辅助栈将元素倒置
> - 退栈对比
*/


#include<stdio.h>
#include "./utils/utils.c"


bool AncestorStack(BiTree T, ElemType x, Stack *St){
    Stack S; InitStack(&S);
    BiTree p=T, r=NULL;
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
                if(p->data == x){
                    Push(&S, p);
                    break;
                }
                r = p;
                p = NULL;
            }
        }
    }
    while(!StackEmpty(S)){
        Pop(&S, &p);
        Push(St, p);
    }
    return true;
}


ElemType AncestorTree(BiTree T, ElemType x, ElemType y){
    Stack S1; InitStack(&S1);
    Stack S2; InitStack(&S2);
    BiTree p1, p2, pre;
    AncestorStack(T, x, &S1);
    AncestorStack(T, y, &S2);

    while(!(StackEmpty(S1) || StackEmpty(S2))){
        Pop(&S1, &p1);
        Pop(&S2, &p2);
        if(p1->data != p2->data)
            break;
        pre = p1;
    }
    return pre->data;
}


int main(){
    FILE *fp;
    BiTree T;
    fp = fopen("data.txt", "r");
    InitBiTree(&T);
    CreateBiTree(fp, &T);
    PrintTree(T);

    ElemType x = 'E', y = 'G', ch;
    ch = AncestorTree(T, x, y);
    printf("\n[%c, %c]'s Ancestor==>[%c]\n", x, y, ch);

    return 0;
}