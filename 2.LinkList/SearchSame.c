/*
8.找两个链表的公共节点。

> 在公共节点以后，两个链表的节点是相同的。
>
> 1. 求长度，记为len1，len2(len1 > len2)
> 2. L1遍历len1-len2个节点
> 3. 依次比较接下来两个链表的节点是否相等
*/



#include<stdio.h>
#include "./utils/utils.c"


LNode *Search_Same(LinkList L1, LinkList L2){
    int len1 = Length(L1), len2 = Length(L2);
    LNode *pl, *ps;
    pl = len1 > len2?L1->next:L2->next;
    ps = len1 < len2?L1->next:L2->next;
    int dst = len1 > len2?len1-len2:len2-len1;

    while(dst--)
        pl = pl->next;

    while(pl && ps){
        if(pl == ps)
            return pl;
        else{
            pl = pl->next;
            ps = ps->next;
        }
    }
    return NULL;
}


int main(){
    LinkList L1, L2;
    ElemType s = 4, t = 17;
    InitList(&L1);
    InitList(&L2);
    for(int i = 1; i <= 6; ++i){
        ListInsert(L1, i, 2*i);
    }
    printf("List1==>");
    PrintList(L1);
    for(int i = 1; i <= 6; ++i){
        ListInsert(L2, i, 2*i+9);
    }
    printf("List2==>");
    PrintList(L2);
    LNode *p1 = L1->next, *p2 = L2->next;
    for(int i = 0; i < 3; ++i){
        p1 = p1->next;
    }
    while(p2->next)
        p2 = p2->next;
    p2->next = p1;
    printf("List2 after insert==>");
    PrintList(L2);

    LNode *p;
    p = Search_Same(L1, L2);
    printf("The Same Node==>%d\n", p->data);
    return 0;
}