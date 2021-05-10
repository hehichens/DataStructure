/*
15.A和B是两个递增单链表，求A和B的并集，结果保存在A。
- pa、pb分别指向A、B
- 若pa<pb，则pa向后指，并且删除节点
- 若pb<pa，则pb向后指
- 若pb=pa，pa、pb都向后指， 保留节点
*/


#include<stdio.h>
#include "./utils/utils.c"


bool UnionList(LinkList A, LinkList B){
    LNode *pa = A->next, *prea = A, *pb = B->next;
    while(pa&&pb){
        if(pa->data < pb->data){
            prea->next = pa->next;
            free(pa);
            pa = prea->next;
        }
        else if(pa->data > pb->data){
            pb = pb->next;
        }
        else{
            pa = pa->next;
            prea = prea->next;
            pb = pb->next;
        }
    }

    if(pa){
        prea->next = NULL;
        DestroyList(&pa);
    }
    DestroyList(&pb);
    return true;
}


int main(){
    LinkList L1, L2, L;
    InitList(&L1);
    InitList(&L2);
    for(int i = 1; i <= 6; ++i){
        ListInsert(L1, i, 2*i);
    }
    for(int i = 1; i <= 10; ++i){
        ListInsert(L2, i, i);
    }

    printf("List1==>");
    PrintList(L1);
    printf("List2==>");
    PrintList(L2);
    UnionList(L1, L2);
    printf("Merge List==>");
    PrintList(L1);
    return 0;
}