/*
10.将链表A拆解为A和B，A保存奇数元素，B保存偶数元素。

> 将A中的偶数节点移动到B中。
*/


#include<stdio.h>
#include "./utils/utils.c"


bool Split_List(LinkList L1, LinkList L2){
    LNode *p1 = L1->next, *p2 = L2, *pre;
    int i = 1;
    while(p1){
        if(i%2){
            pre = p1;
            p1 = p1->next;
        }
        else{
            pre->next = p1->next;
            p1->next = NULL;
            p2->next = p1;
            p2 = p1;
            p1 = pre->next;
        }
        i++;
    }
    return true;
}


int main(){
    LinkList L1, L2;
    InitList(&L1);
    InitList(&L2);
    for(int i = 1; i <= 12; ++i){
        ListInsert(L1, i, i);
    }

    printf("List1==>");
    PrintList(L1);
    Split_List(L1, L2);
    printf("After Process...\n");
    printf("List1==>");
    PrintList(L1);
    printf("List2==>");
    PrintList(L2);
    return 0;
}