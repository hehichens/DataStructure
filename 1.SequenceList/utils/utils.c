#include "utils.h"


/*base functions*/
bool InitList(SqList *L){
    L->data = (ElemType*)malloc(InitSize * sizeof(ElemType));
    if(!L->data)
        exit(-1);
    L->length = 0;

    return true;
}


int Length(SqList L){
    return L.length;
}


int LocateElem(SqList L, ElemType e){
    int i;
    for(int i=0; i < L.length; ++i){
        if(L.data[i] == e)
            return i+1;
    }
    return 0;
}


ElemType GetElem(SqList L, int i){
    return L.data[i];
}


bool ListInsert(SqList *L, int i, ElemType e){
    if(i < 1 || i > L->length+1) 
        return false;

    if(L->length >= MaxSize)
        return false;

    for(int j=L->length; j >= i; j--)
        L->data[j] = L->data[j-1];
    L->data[i-1]=e;
    L->length++;
    return true;
}


bool ListDelete(SqList *L, int i, ElemType *e){
    if(i < 1 || i > L->length)
        return false;

    *e = L->data[i-1];
    for(int j=i; j < L->length; ++j)
        L->data[j-1] = L->data[j];
    L->length--;
    return true;
}


bool PrintList(SqList L){
    for(int i = 0; i < L.length; ++i)
        printf("%d ", L.data[i]);
    printf("\n");
    return true;
}

bool Empty(SqList L){
    return L.length == 0?true:false;
}

bool DestroyList(SqList *L){
    free((L->data));

    L->data = NULL;
    L->length = 0;
    return true;
}




/*other functinos*/
bool swap(ElemType *e1, ElemType *e2){
    ElemType temp = *e1;
    *e1 = *e2;
    *e2 = temp;
    return true;
}