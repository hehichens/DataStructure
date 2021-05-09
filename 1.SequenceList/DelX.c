/*
3.对长度为n的顺序表L， 删除L中所有值为x的数据元素。
*/

#include<stdio.h>
#include "./utils/utils.c"


/*
将L中不等于x的值按顺序保存， 用k记录不等于x的个数，最后长度修改为k。
*/
bool Del_x_1(SqList *L, ElemType x){
    int k = 0;
    for(int i = 0; i < L->length; ++i){
        if(L->data[i] != x)
            L->data[k++] = L->data[i];
    }
    L->length = k;
    return true;
}


/*
用k记录L中等于x的个数，边扫描边统计k， 将不等于x的值向前移动k个位置。
*/
bool Del_x_2(SqList *L, ElemType x){
    int k = 0;
    for(int i = 0; i < L->length; ++i){
        if(L->data[i] == x)
            k++;
        else
            L->data[i-k] = L->data[i];
    }
    L->length -= k;
    return true;
}


int main(){
    SqList L;
    int x = 4;

    printf("Method 1: \n");
    InitList(&L);
    for(int i = 1; i <= 6; ++i)
        ListInsert(&L, i, 2*i);
    ListInsert(&L, 3, 4);
    ListInsert(&L, 4, 4);
    printf("List==>");
    PrintList(L);

    Del_x_1(&L, x);
    printf("New List==>");
    PrintList(L);

    printf("======================================================\n");

    printf("Method 2: \n");
    ListInsert(&L, 2, 4);
    ListInsert(&L, 3, 4);
    ListInsert(&L, 4, 4);
    printf("List==>");
    PrintList(L);

    Del_x_2(&L, x);
    printf("New List==>");
    PrintList(L);
    return 0;
}