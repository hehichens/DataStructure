1.从顺序表删除最小元素（假设唯一）并返回该值，空出的位置由最后一个元素填补。

```c
bool Del_Min(SqList *L, ElemType *value){
    if(!L->length)
        return false;

    int min = 0;
    for(int i = 1; i < L->length; ++i){
        if(L->data[min] > L->data[i])
            min = i;
    }
    *value = L->data[min];
    L->data[min] = L->data[--L->length];
    return true;
}
```



2.将顺序表逆置，空间复杂度要求O(1)。

```C
bool ReverseList(SqList *L){
    if(!L->length)
        return false;

    for(int i=0, j=L->length-1; i < j; ++i,--j){
        swap(&L->data[i], &L->data[j]);
    }
    return true;
}
```



3.对长度为n的顺序表L， 删除L中所有值为x的数据元素。

方法一

> 将L中不等于x的值按顺序保存， 用k记录不等于x的个数，最后长度修改为k。

```C
bool Del_x_1(SqList *L, ElemType x){
    int k = 0;
    for(int i = 0; i < L->length; ++i){
        if(L->data[i] != x)
            L->data[k++] = L->data[i];
    }
    L->length = k;
    return true;
}
```

方法二

> 用k记录L中等于x的个数，边扫描边统计k， 将不等于x的值向前移动k个位置。

```C
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
```



4.删除有序顺序表中s与t之间（s<t）的所有元素。

方法一

> 同第三题方法一，将L中小于等于s，大于等于t的值按顺序保存， 用k记录不等于x的个数，最后长度修改为k。

```c
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

```

方法二

> 由于是有序表，只需要找到大于等于s的第一个元素与大于等于t的第一个元素，将删除这段，只需将后面的元素前移。

```c
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
```



6.从有序表中删除重复的元素。

```c
bool Del_Same(SqList *L){
    int k = 0;
    ElemType flag = L->data[0];
    L->data[k++] = flag;
    for(int i = 1; i < L->length; ++i){
        if(L->data[i] != flag){
            flag = L->data[i];
            L->data[k++] = flag;
        }
    }
    L->length = k;
    return true;
}
```



7.将两个有序顺序表合并为一个有序顺序表。

```c
bool MergeList(SqList *L1, SqList *L2, SqList *L){
    int i=0, j=0, k=0;
    while(i < L1->length && j < L2->length){
        if(L1->data[i] < L2->data[j])
            L->data[k++] = L1->data[i++];
        else
            L->data[k++] = L2->data[j++];
    }

    while(i < L1->length){
            L->data[k++] = L1->data[i++];
    }
    while(j < L2->length){
            L->data[k++] = L2->data[j++];
    }
    L->length = k;
    return true;
}

```



8.一维数组A[m+n]存放了两个顺序表，将两个顺序表位置互换。

> 先将整体逆置，再讲两个顺序表分别逆置

```C
bool ReverseList(SqList *L, int m, int n){
    if(m > n) return false;

    for(int i=m, j=n-1; i < j; ++i,--j){
        swap(&L->data[i], &L->data[j]);
    }
    return true;
}


bool ExchangeList(SqList *L, int m){
    ReverseList(L, 0, L->length);
    ReverseList(L, 0, m);
    ReverseList(L, m, L->length);
    return true;
}
```



9.顺序表按递增顺序存储，查找x，若找到，则将其与后继元素互换，否则将其插入表中并且仍使得顺序表递增。

```C
bool Search_Exchange(SqList *L, ElemType x){
    int i;
    for(i = 0; i < L->length-1 && x > L->data[i]; ++i);

    if(x == L->data[i])
        swap(&L->data[i], &L->data[i+1]);
    else{
        ListInsert(L, i+1, x);
    }
    return true;
}
```



11.【真题】求两个升序序列A、B的中位数。

A、B的中位数分别为mid1、mid2

- mid1 = mid2，即为所求中位数
- mid1 < mid2，舍弃A中较小的部分，舍弃B中较大的部分
- mid1 > mid2，舍弃A中较大的部分，舍弃B中较小的部分（舍弃长度相等）

```C
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
```



12.【真题】整数序列A=(a0, a1, a2,...,an-1)，其中0<=ai<n。存在a_p1=a_p2=...=a_pm=x且m > m/2(0<=pk<n, 1<=k<=m)，则称x为A的主元素。如A=(0, 5, 5, 3, 5, 7, 5, 5)中5的个数为5>8/2=4，所以5是主元素。

> - 选取候选主元素。初始化count=1，扫描整个顺序表，遇见主元素count++,遇见非主元素count--，count为0时则换主元素。
> - 扫描一次确认该元素就是主元素

```c
int MarjorityList(SqList *L, ElemType x){
    int count, flag, i;
    flag = L->data[0];
    for(i = 1; i < L->length; ++i){
        if(L->data[i] == flag) count++;
        else{
            if(count) count--;
            else{
                flag = L->data[i];
                count = 1;
            }
        }
    }

    if(count){
        for(i=count=0; i < L->length; ++i)
            if(L->data[i] == x)
                count++;
    }
    if(count > L->length/2) return true;
    else return false;
}
```



13.【真题】找出顺序表中未出现的最小整数。{-5, 3, 2, 3}中为1；{1, 2, 3}中为4。

> 空间换时间

```c
int Find_Miss_Min(SqList *L){
    int i;
    ElemType *B = (ElemType *)malloc(sizeof(ElemType) * SIZE);
    memset(B, 0, sizeof(ElemType)*SIZE);
    for(i = 0; i < L->length; ++i)
        if(L->data[i] > 0 && L->data[i] < SIZE)
            B[L->data[i]] = 1;

    for(i = 1; i < SIZE; ++i)
        if(!B[i]) break;
    return i;
}
```



14.三元组(a, b, c) 的距离D=|a-b| + |b-c| + |c-a|。a, b, c分别在三个升序的数组S1, S2, S3中。

> - D_min = INF
> - i=j=k=0. 
>   1. 计算A[i], B[j], C[k] 的距离D
>   2. 若D<D_min，则D_min=D
>   3. 将A[i], B[j], C[k]中最小值的下标+1
> - 输出D_min

```c
int Find_Min_of_Trip(SqList *L1, SqList *L2, SqList *L3){
    int i=0, j=0, k=0;
    int a, b, c;
    ElemType D_min = 0x7fffffff;
    while (i < L1->length && j < L2->length && k < L3->length && D_min > 0){
        a = L1->data[i];
        b = L2->data[j];
        c = L3->data[k];
        ElemType D = abs(a-b) + abs(b-c) + abs(c-a);
        if(D < D_min) D_min = D;
        
        if(isMin(a, b, c)) i++;
        else if(isMin(b, a, c)) j++;
        else k++;
    }
    return D_min;
}
```







