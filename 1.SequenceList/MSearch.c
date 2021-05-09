/*
11.求两个升序序列A、B的中位数。
*/


#include<stdio.h>
#include "./utils/utils.c"

ElemType M_search(SqList *L1, SqList *L2){
    int flag;
    int mid1=0, mid2=1;
    int s1 = 0, d1 = L1->length-1, s2 = 0, d2 = L2->length-1;
    while(s1 != d1 || s2 != d2){
        mid1 = (s1 + d1) / 2;
        mid2 = (s2 + d2) / 2;

        if(L1->data[mid1] < L2->data[mid2]){
            flag = ((s1 + d1)%2)?1:0;
            s1 = mid1 + flag;
            d2 = mid2;
        }
        else{
            flag = ((s2 + d2)%2)?1:0;
            d1 = mid1;
            s2 = mid2+1;
        }
    }//while
    return L1->data[mid1] < L2->data[mid2]?L1->data[mid1]:L1->data[mid2];
}


int main(){
    SqList L1, L2;
    int s1[] = {11, 13, 15, 17, 19};
    int s2[] = {2, 4, 6, 8, 20};
    InitList(&L1);
    InitList(&L2);
    for(int i = 1; i < 6; ++i)
        ListInsert(&L1, i, s1[i-1]);
    for(int i = 1; i < 6; ++i)
        ListInsert(&L2, i, s2[i-1]);

    printf("List1==>");
    PrintList(L1);
    printf("List2==>");
    PrintList(L2);

    ElemType num = M_search(&L1, &L2);
    printf("Midle number ==> %d\n", num);
    return 0;
}