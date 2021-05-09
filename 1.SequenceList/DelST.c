/*
4.删除有序顺序表中s与t之间（s<t）的所有元素。
*/

#include<stdio.h>
#include "./utils/utils.c"

/*
同第三题方法一，将L中小于等于s，大于等于t的值按顺序保存， 用k记录不等于x的个数，最后长度修改为k。
*/
bool Del_s_t_1(SqList *L, ElemType s, ElemType t){
    if(s >= t || L->length == 0)
        return false;

    int k = 0;
    for(int i = 0; i < L->length; ++i){
        if(L->data[i] <= s || L->data[i] >= t)
            L->data[k++] = L->data[i];
    }
    L->length = k;
    return true;
}


/*
由于是有序表，只需要找到大于等于s的第一个元素与大于等于t的第一个元素，将删除这段，只需将后面的元素前移。
*/
bool Del_s_t_2(SqList *L, ElemType s, ElemType t){
    if(s >= t || L->length == 0)
        return false;

    int i, j;
    for(i = 0; i < L->length && L->data[i] < s; ++i);
    if(i == L->length) return false;

    for(j = i; i < L->length && L->data[j] < t; ++j);
    if(j == L->length) return false;

    for(; j < L->length; ++i, ++j)
        L->data[i] = L->data[j];
    L->length = i;
    return true;
}


int main(){
    SqList L;
    int s = 3;
    int t = 10;
    printf("s=%d, t=%d\n", s, t);

    printf("Method 1:\n");
    InitList(&L);
    for(int i = 1; i <= 7; ++i)
        ListInsert(&L, i, 2*i);

    printf("List==>");
    PrintList(L);
    
    Del_s_t_1(&L, s, t);
    printf("New List==>");
    PrintList(L);

    DestroyList(&L);
    printf("=======================================================\n");

    printf("Method 2:\n");
    InitList(&L);
    for(int i = 1; i <= 7; ++i)
        ListInsert(&L, i, 2*i);

    printf("List==>");
    PrintList(L);

    Del_s_t_2(&L, s, t);
    printf("New List==>");
    PrintList(L);

    return 0;
}