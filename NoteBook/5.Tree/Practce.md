4.写出自下而上，从右到左的层次遍历算法。

> 利用原来层次遍历的方法，将遍历的结点全部压栈，再全部出栈。

```c
bool Intervel_Level(BiTree T){
    Queue Q; InitQueue(&Q);
    Stack S; InitStack(&S);
    BiTree p=T;
    EnQueue(&Q, p);
    while(!QueueEmpty(Q)){
        DeQueue(&Q, &p);
        Push(&S, p);
        if(p->lchild) EnQueue(&Q, p->lchild);
        if(p->rchild) EnQueue(&Q, p->rchild);
    }

    while(!StackEmpty(S)){
        Pop(&S, &p);
        printf("%c ", p->data);
    }
    printf("\n");
    return true;
}
```



5.【掌握】采用非递归的方法计算树的高度。

> - level记录当前所在层数
>
> - last指向当前层最右结点
> - 层次遍历完出队时与last对比，相等则level++，last指向下层最右结点

```c
int BT_Depth(BiTree T){
    BiTree last = T, p = T;
    int level = 0;
    Queue Q; InitQueue(&Q);
    EnQueue(&Q, p);
    while(!QueueEmpty(Q)){
        DeQueue(&Q, &p);
        if(p == last){
            level++;
            if(p->rchild) last = p->rchild;
            else last = p->lchild;
        }
        if(p->lchild) EnQueue(&Q, p->lchild);
        if(p->rchild) EnQueue(&Q, p->rchild);

    }
    return level;
}
```



6.二叉树的先序和中序遍历分别保存在A、B数组中， 建立二叉树的二叉链表。

> - 在先序中确定树的根结点
> - 根据根节点将中序划分为左右子树



7.判断一个树是不是完全二叉树。
> - 采用层次遍历的思想
> - 遇到空结点，则查看队列后面是否有*非空结点*，若有则不是完全二叉树。

```c
bool Is_Complete_Tree(BiTree T){
    Queue Q; InitQueue(&Q);
    BiTree p;
    p = T;
    EnQueue(&Q, p);
    while(!QueueEmpty(Q)){
        DeQueue(&Q, &p);
        if(p){
            EnQueue(&Q, p->lchild);
            EnQueue(&Q, p->rchild);
        }
        else{
            while(!QueueEmpty(Q)){
                DeQueue(&Q, &p);
                if(p) return false;
            }
        }
    }
    return true;
}
```



8.统计二叉树所有双分支结点的个数

> - f(b) = 0 if b = NULL;
> - f(b) = f(b->lchild) + f(b->rchild) + 1 if *b has double son nodes;
> - f(b) = f(b->lchild) + f(b->rchild) if *b is other nodes.

```c
int Dson_Nodes(BiTree b){
    if(b == NULL) 
        return 0;
    else if(b->lchild && b->rchild)
        return Dson_Nodes(b->lchild) + Dson_Nodes(b->rchild) + 1;
    else
        return Dson_Nodes(b->lchild) + Dson_Nodes(b->rchild);
}
```



9. 交换树T中所有的左右子树。
> 1. 交换T左孩子的左右子树
> 2. 交换T右孩子的左右子树
> 3. 交换T的左右子树

```c
void Swap_Tree(BiTree T){
    if(T){
        Swap_Tree(T->lchild);
        Swap_Tree(T->rchild);
        BiTree temp = T->lchild;
        T->lchild = T->rchild;
        T->rchild = temp;
    }
}
```



10.求先序遍历中第k个值

方法一

> 使用栈求现需遍历，并且计数

```c
BiTree Pre_K(BiTree T, int k){
    Stack S; InitStack(&S);
    BiTree p = T;
    while((p || !StackEmpty(S)) &&k){
        if(p){
            Push(&S, p);
            p = p->lchild;
            k--;
            // if(!k) break;
        }
        else{
            Pop(&S, &p);
            p = p->rchild;
        }
    }
    Pop(&S, &p);
    return p;
}
```

方法二

> 使用全局变量i记录已访问过节点的序号。二叉树T为空时返回‘#’。
>
> - i==k，返回T->data
> - i ≠ k，递归地在左子树查找，还没则找到继续在右子树查找。

```c
int i = 1;
ElemType Pre_K_2(BiTree T, int k){
    if(!T) 
        return '#';
    if(i == k)
        return T->data;

    char ch;
    i++;
    ch = Pre_K_2(T->lchild, k);
    if(ch != '#') return ch;
    ch = Pre_K_2(T->rchild, k);
    return ch;
}

```





11.对于值为x的结点，删除以它为根的子树并释放对应空间。

> - 层次遍历找到值为x的结点
> - 递归的删除以x为根的树

```c
void Del_Tree(BiTree T){
    if(T->lchild) Del_Tree(T->lchild);
    if(T->rchild) Del_Tree(T->rchild);
    free(T);
}
void Del_x(BiTree T, ElemType x){
    Queue Q; InitQueue(&Q);
    BiTree p = T;
    EnQueue(&Q, p);
    while(!QueueEmpty(Q)){
        DeQueue(&Q, &p);
        if(p->lchild){
            if(p->lchild->data == x){
                Del_Tree(p->lchild);
                p->lchild = NULL;
            }
            else
                EnQueue(&Q, p->lchild);
        }
        if(p->rchild){
            if(p->rchild->data == x){
                Del_Tree(p->rchild);
                p->rchild = NULL;
            }
            else
            EnQueue(&Q, p->rchild);
        }
    }
}
```



12.打印x结点的所有祖先

> - 采用后序遍历
> - 栈中，x之前的元素都是x的祖先，因此只需要找到x，再依次出栈即可。

```c
bool Print_Parents(BiTree T, ElemType x){
    Stack S; InitStack(&S);
    BiTree r=NULL, p=T;
    while(p || !StackEmpty(S)){
        if(p){
            Push(&S, p);
            p = p->lchild;
        }
        else{
            GetTop(S, &p);
            if(p->rchild && p->rchild != r){
                p = p->rchild;
            }
            else{
                Pop(&S, &p);
                // printf("%c ", p->data);
                if(p->data == x)
                break;
                r = p;
                p = NULL;
            }
        }
    }
    while(!StackEmpty(S)){
        Pop(&S, &p);
        printf("%c ", p->data);
    }
    printf("\n");
    return true;
}
```



13.找到p、q最近的公共祖先结点r。

> - 采用后序遍历
> - 将p、q的祖先分别保存到栈中
> - 使用辅助栈将元素倒置
> - 退栈对比

```c
bool AncestorStack(BiTree T, ElemType x, Stack *St){
    Stack S; InitStack(&S);
    BiTree p=T, r=NULL;
    while(p || !StackEmpty(S)){
        if(p){
            Push(&S, p);
            p = p->lchild;
        }
        else{
            GetTop(S, &p);
            if(p->rchild && p->rchild != r){
                p = p->rchild;
            }
            else{
                Pop(&S, &p);
                if(p->data == x){
                    Push(&S, p);
                    break;
                }
                r = p;
                p = NULL;
            }
        }
    }
    while(!StackEmpty(S)){
        Pop(&S, &p);
        Push(St, p);
    }
    return true;
}


ElemType AncestorTree(BiTree T, ElemType x, ElemType y){
    Stack S1; InitStack(&S1);
    Stack S2; InitStack(&S2);
    BiTree p1, p2, pre;
    AncestorStack(T, x, &S1);
    AncestorStack(T, y, &S2);

    while(!(StackEmpty(S1) || StackEmpty(S2))){
        Pop(&S1, &p1);
        Pop(&S2, &p2);
        if(p1->data != p2->data)
            break;
        pre = p1;
    }
    return pre->data;
}
```



14.求二叉树宽度

> 采用层次遍历的思想，count统计当前层结点数，count >max则更新max，last指针指向当前层最右的结点。

```c
int BT_Width(BiTree T){
    Queue Q; InitQueue(&Q);
    BiTree p = T, last = T;
    int max=0, count=0;
    EnQueue(&Q, p);
    while(!QueueEmpty(Q)){
        DeQueue(&Q, &p);
        count++;
        if(p == last){
            if(max < count) max = count;
            
            if(p->rchild) last = p->rchild;
            else last = p->lchild;

            count = 0;
        }
        if(p->lchild) EnQueue(&Q, p->lchild);
        if(p->rchild) EnQueue(&Q, p->rchild);
    }
    return max;
}
```



15.有一棵满二叉树， 根据先序序列求后序序列。

> - 先序结点的第一个节点为后序结点的最后一个结点
> - 对每一棵子树递归

```c
void PreToPost(ElemType *pre, ElemType *post, int l1, int h1, int l2, int h2){
    if(l1 <= h1){
        post[h2] = pre[l1];
        int half = (h1 - l1) / 2;
        PreToPost(pre, post, l1+1, l1+half, l2, l2+half-1);
        PreToPost(pre, post, l1+half+1, h1, l2+half, h2-1);
    }
}
```



16.把二叉树的叶结点从左到右连成一个单链表。

> 前中后遍历都可以， pre指向上一个叶结点

```c
BiNode *head, *pre=NULL;
BiTree TreeToList(BiTree T){
    if(T){
        if(T->lchild == NULL && T->rchild == NULL){
            if(pre==NULL){
                head = T;
                pre = T;
            }
            else{
                pre->rchild = T;
                pre = T;
            }
        }
        TreeToList(T->lchild);
        TreeToList(T->rchild);
        pre->rchild = NULL;
    }
    return head;
}
```



17.判断两棵二叉树是否相似。

> - f(T1, T2)=1, if T1 == T2 == NULL;
> - f(T1, T2)=0, if one of them is NULL and another is not NULL;
> - f(T1, T2) = f(T1->lchild, T2->lchild) &&  f(T1->rchild, T2->rchild) , if T1 != NULL and T2 != NULL.

```c
bool Similar_Tree(BiTree A, BiTree B){
    if(A == NULL && B == NULL)
        return true;
    else if(A != NULL && B != NULL)
        return Similar_Tree(A->lchild, B->lchild) && Similar_Tree(A->rchild, B->rchild);
    else
        return false;
}
```



19.计算所有叶结点的带权路径之和。

> - 基于先序遍历
> - 设置全局变量wpl；
> - 如果是叶结点，wpl += deep * p->data

```c
int WPL(BiTree T, int deep){
    static int wpl = 0;
    if(T){
        if(T->lchild == NULL && T->rchild == NULL){
            int data = T->data - '0';
            wpl += deep*data;
        }
        WPL(T->lchild, deep+1);
        WPL(T->rchild, deep+1);
    }
    return wpl;
}
```



20.根据表达式构成的二叉树输出中缀表达式

> - 采用中序遍历
> - 遍历左子树之前加左括号，遍历完右子树之后加右括号
> - 叶结点直接打印

```c
void TreeToExp(BiTree T, int deep){
    if(T == NULL) return ;
    else if(T->lchild == NULL && T->rchild == NULL)
        printf("%c", T->data);
    else{
        if(deep) printf("(");
        TreeToExp(T->lchild, deep+1);
        printf("%c", T->data);
        TreeToExp(T->rchild, deep+1);
        if(deep) printf(")");
    }
}
```

