/*
5.删除带头结点链表中的介于s、t（s<t）的值。
> 逐点检查然后删除
*/

#include<stdio.h>
#include "./utils/utils.c"


bool Range_Delete(LinkList L, ElemType s, ElemType t){
    LNode *p = L->next, *pre = L;
    while(p){
        if(p->data > s && p->data < t){
            pre->next = p->next;
            free(p);
            p = pre->next;
        }
        else{
            pre = pre->next;
            p = p->next;
        }
    }
    return true;
}



int main(){
    LinkList L;
    ElemType s = 4, t = 17;
    InitList(&L);
    for(int i = 1; i <= 10; ++i){
        ListInsert(L, i, 2*i);
    }

    printf("List==>");
    PrintList(L);

    printf("s=%d, t=%d\n", s, t);
    Range_Delete(L, s, t);
    printf("New List==>");
    PrintList(L);
    return 0;
}