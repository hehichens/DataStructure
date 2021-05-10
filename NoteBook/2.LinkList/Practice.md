1.用递归实现：删除不带头结点的单链表L中所有值为x的节点。

```c
void Del_x(LinkList *L, ElemType x){
    if(*L == NULL) return ;

    if((*L)->data == x){
        LNode *p = *L;
        *L = (*L)->next;
        free(p);
        Del_x(L, x);
    }
    else Del_x(&(*L)->next, x);
}
```

知识点：

> 是否使用 LinkList *L 看L节点有没有被修改



2.删除带头结点单链表L中所有x的节点。

```c
bool Del_x_2(LinkList *L, ElemType x){
    LNode *p = (*L)->next;
    LNode *pre = NULL, *q = NULL;
    while(p){
        if(p->data == x){
            q = p;
            p = p->next;
            pre->next = p;
            free(q);
        }
        else{
            pre = p;
            p = p->next;
        }
    }
    return true;
}

```



3.反向输出带头结点链表的值。

>  不是尾节点则递归，是则输出值。

```c
void Reverse_Print(LinkList L){
    if(L->next) 
        Reverse_Print(L->next);
    if(L) printf("%d ", L->data);
}

bool R_Print(LinkList L){
    Reverse_Print(L->next);
    printf("\n");
    return true;
}
```



4.删除带头结点链表中的最小值。

```c
LNode *p, *pre, *minp, *minpre;
    pre = L;
    p = L->next;
    minpre = L;
    minp = L->next;
    while(p){
        if(p->data < minp->data){
            minpre = pre;
            minp = p;
        }
        pre = p;
        p = p->next;
    }

    // delete min node
    minpre->next = minp->next;
    free(minp);
    return true;
```



5.逆置带头结点链表。

> 遍历节点，依次插入到头结点后面

```c
bool Reverse_Link(LinkList L){
    LNode *p = L->next, *q;
    L->next = NULL;
    while(p){
        q = p->next;
        p->next = L->next;
        L->next = p;
        p = q;
    }
    return true;
}
```



6.将带有头结点的单链表递增排序。

> 采取直接插入排序，p为工作指针，通过pre指针寻找p节点插入的位置。

```c
bool SortLink(LinkList L){
    LNode *p, *pre, *r;
    p = L->next;
    r = p->next;
    p->next = NULL;
    p = r;
    while(p){
        r =p->next;
        pre = L;
        while(pre->next && pre->next->data < p->data)
            pre = pre->next;
        p->next = pre->next;
        pre->next = p;
        p = r;
    }
    return true;
}
```



7.删除带头结点链表中的介于s、t（s<t）的值。

> 逐点检查然后删除

```c
bool Range_Delete(LinkList L, ElemType s, ElemType t){
    LNode *p = L->next, *pre = L;
    while(p){
        if(p->data > s && p->data < t){
            pre->next = p->next;
            free(p);
            p = pre->next;
        }
        else{
            pre = pre->next;
            p = p->next;
        }
    }
    return true;
}
```



8.找两个链表的公共节点。

> 在公共节点以后，两个链表的节点是相同的。
>
> 1. 求长度，记为len1，len2(len1 > len2)
> 2. L1遍历len1-len2个节点
> 3. 依次比较接下来两个链表的节点是否相等

```c
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
```



9.按照递增次序输出单链表各节点的数据，并释放所占空间。

> 1.依次遍历找到最小节点
>
> 2.输出并删除该节点

```c
bool Sort_Print(LinkList L){
    while(L->next)
        Del_Min(L);
    printf("\n");
    return true;
}
```



10.将链表A拆解为A和B，A保存奇数元素，B保存偶数元素。

> 将A中的偶数节点移动到B中。

```c
bool Split_Link(LinkList L1, LinkList L2){
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
```



11.C={a1, b1, a2, b2, ..., an, bn}为线性表，拆分得到两个线性表，A={a1, a2, ..., an}，B={b1, b2, ..., bn}。

> 同10，B采用头插法

```c
bool Split_Link_2(LinkList L1, LinkList L2){
    LNode *p1 = L1->next, *pre;
    int i = 1;
    while(p1){
        if(i%2){
            pre = p1;
            p1 = p1->next;
        }
        else{
            pre->next = p1->next;
            p1->next = L2->next;
            L2->next = p1;
            p1 = pre->next;
        }
        i++;
    }
    return true;
}
```



12.删除有序链表中的重复值。

> 将p与其下一个节点比较
>
> - 若相等则删除该节点
> - 若不相等则p向后指

```c
bool Del_Same(LinkList L){
    LNode *p = L, *r;
    while(p->next){
        if(p->data == p->next->data){
            r = p->next;
            p->next = p->next->next;
            free(r);
        }
        else
            p = p->next;
    }
    return true;
}
```



13.将两个递增有序的线性表合并为一个递减有序的线性表。

> 设置两个指针p1, p2，比较p1, p2
> - 若p1 <= p2，则将p1头插到L
> - 若p1 > p2，则将p2头插到L
>

```c
bool Move(LinkList L1, LinkList L2){
    /*Move the first node of L1 and insert it to L2 with head.*/
    LNode *r = L1->next;
    L1->next = L1->next->next;
    r->next = L2->next;
    L2->next = r;
    return true;
}

bool MergeLink(LinkList L1, LinkList L2, LinkList L){
    while(L1->next && L2->next){
        if(L1->next->data <= L2->next->data)
            Move(L1, L);
        else
            Move(L2, L);
    }
    if(L1->next == NULL){
        while(L2->next)
            Move(L2, L);
    }
    else{
        while(L1->next)
            Move(L1, L);
    }
    free(L1);
    free(L2);
    return true;
}
```



14.A和B是两个递增的单链表，从A、B的公共元素中产生C。

> - 值小的指针往后移
> - 两节点相等时，将后面的节点复制到C

```c
bool Get_Common(LinkList A, LinkList B, LinkList C){
    LNode *pa, *pb, *pc, *p;
    pa = A->next;
    pb = B->next;
    pc = C;
    while(pa && pb){
        if(pa->data < pb->data)
            pa = pa->next;
        else if(pa->data > pb->data)
            pb = pb->next;
        else{
            p = (LNode *)malloc(sizeof(LNode));
            p->data = pa->data;
            pc->next = p;
            pc = p;  

            pa = pa->next;
            pb = pb->next;          
        }
    }

    if(!pa) pa = pb;
    while(pa){
        p = (LNode *)malloc(sizeof(LNode));
        p->data = pa->data;
        pc->next = p;
        pc = p;
        pa = pa->next;
    }

    pc->next = NULL;
    return true;
}
```



15.A和B是两个递增单链表，求A和B的并集，结果保存在A。

> - pa、pb分别指向A、B
> - 若pa<pb，则pa向后指，并且删除节点
> - 若pb<pa，则pb向后指
> - 若pb=pa，pa、pb都向后指， 保留节点

```c
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
```



16.判断单链表B是否为A的连续子序列。

> 暴力匹配

```c
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
```



21.查找链表上倒数第k个位置的节点（不改变链表）。

方法一

> 求取链表长度为len，返回第len-k个节点

```c
ElemType Search_k_1(LinkList L, int k){
    int len = Length(L);
    len -= k;
    LNode *p = L->next;
    while(len--){
        p = p->next;
    }
    return p->data;
}

```

方法二

> - p指针从头结点移动k个位置
> - q指针指向头结点， p、q同时移动

```c
ElemType Search_k_2(LinkList L, int k){
    LNode *p = L->next, *q = L->next;
    while(k--)
        p = p->next;
    while(p){
        p = p->next;
        q = q->next;
    }
    return q->data;
}
```



22.用单链表保存单词，找到两个单词共同后缀的起始位置。

>参考第8题寻找公共节点，结合21题的方法。
>
>- 求出A、B链表的长度lenA、lenB
>- pa、pb分别指向A、B的头结点
>- 假设A更长，pa先向后指lenA-lenB次
>- pa、pb同时向后指，直到pa、pb指向同一位置

```c
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
```



23.对于绝对值相等的结点， 仅保留第一次出现的结点而删除其他的结点。

> 用数组A保存访问过的结点，绝对值相同的结点保存在同一位置
>
> - 若该点为0，保留并标记为1
> - 若该点为1，删除。

```c
bool Del_Abs_Same(LinkList L){
    bool A[N+1];
    memset(A, false, N+1);
    LNode *p = L->next, *pre = L;
    while(p){
        if(!A[Abs(p->data)]){
            A[Abs(p->data)] = true;
            pre = p;
            p = p->next;
        }
        else{
            pre->next = p->next;
            free(p);
            p = pre->next;            
        }
    }
    return true;
}
```



25.将单链表L=(a1, a2, a3, ..., a_n-2, a_n-1, a_n) 转化为 L'=(a1, a_n, a2, a_n-1, a3, ..., a_n-2, ...)。

> 1. p指向头结点，q指向中间结点
>    - 找中间，设置两个指针从头指针开始向后指，一个走一步，一个走两步
> 2. 将q之后的链表逆转
> 3. p、q向后指，依次取结点添加



```c
bool Change_List(LinkList L){
    LNode *p = L->next, *q = L->next, *r, *s;
    while(q->next){
        p = p->next;
        q = q->next;
        if(q->next) q = q->next;
    }
    q = p->next;
    p->next = NULL;
    // printf("%d\n", p->data);

    // Reverse
    while(q){
        r = q->next;
        q->next = p->next;
        p->next = q;
        q = r;
    }
    s = L->next;
    q = p->next;
    p->next = NULL;

    while(q){
        r = q->next;
        q->next = s->next;
        s->next = q;
        s = q->next;
        q = r;
    }

    return true;
}

```









