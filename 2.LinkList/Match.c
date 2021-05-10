/*
16.判断单链表B是否为A的连续子序列。
*/

#include<stdio.h>
#include "./utils/utils.c"


bool MatchList(LinkList A, LinkList B){
    LNode *pa=A->next, *pb = B->next, *r;
    r = pa;
    while(pa && pb){
        if(pa->data == pb->data){
            pa = pa->next;
            pb = pb->next;
        }
        else{
            r = r->next;
            pa = r;    
            pb = B->next;
        }
    }
    if(pb == NULL) return true;
    else return false;
}


int main(){
    LinkList L1, L2, L;
    InitList(&L1);
    InitList(&L2);
    for(int i = 1; i <= 6; ++i){
        ListInsert(L1, i, 2*i);
    }
    for(int i = 1; i <= 4; ++i){
        ListInsert(L2, i, 2*i+2);
    }

    printf("List1==>");
    PrintList(L1);
    printf("List2==>");
    PrintList(L2);
    if(MatchList(L1, L2)) printf("Yes!\n");
    else printf("No!\n");
    return 0;
}