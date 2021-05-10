/*
22.用单链表保存单词，找到两个单词共同后缀的起始位置。

>参考第8题寻找公共节点，结合21题的方法。
>
>- 求出A、B链表的长度lenA、lenB
>- pa、pb分别指向A、B的头结点
>- 假设A更长，pa先向后指lenA-lenB次
>- pa、pb同时向后指，直到pa、pb指向同一位置
*/


#include<stdio.h>
#include "./utils/utils.c"


LNode *Find_Addr(LinkList A, LinkList B){
    int lenA = Length(A), lenB = Length(B);
    int len = lenA > lenB ? lenA-lenB:lenB-lenA;
    LNode *pl = lenA > lenB ? A->next:B->next;
    LNode *ps = lenA < lenB ? A->next:B->next;

    while(len--)
        pl = pl->next;

    while(pl && pl != ps){
        pl = pl->next;
        ps = ps->next;
    }
    return pl;
}


int main(){
    LinkList L1;
    LinkList L2;
    char str1[] = {'l', 'o', 'a', 'd', 'i', 'n', 'g', '\0'};
    char str2[] = {'b', 'e', 'i', 'n', 'g','\0'};
    InitList(&L1);
    InitList(&L2);
    for(int i = 1; i <= 7; ++i){
        ListInsert(L1, i, str1[i-1]);
    }
    LNode *q = L1->next;
    for(int i = 1; i <= 4; ++i)
        q = q->next;

    for(int i = 1; i <= 2; ++i){
        ListInsert(L2, i, str2[i-1]);
    }
    LNode *p = L2->next;
    while(p->next) p = p->next;
    p->next = q;

    LNode *r = Find_Addr(L1, L2);
    printf("Character==>[%c]\n", r->data);
    return 0;
}