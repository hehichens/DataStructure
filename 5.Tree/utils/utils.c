/*

*/

#include<stdio.h>
#include<math.h>
#include "utils.h"

/*Binary Tree*/
//Init function
bool InitBiTree(BiTree *T){
    *T = NULL;
    return true;
}


//Create Binary Tree
void CreateBiTree(FILE *fp, BiTree *T){
    char ch;
    bool flag = fscanf(fp, "%c", &ch);
    if(!flag) return ;

    if(ch == '^')
        *T = NULL;
    else{
        *T = (BiNode *)malloc(sizeof(BiNode));
        (*T)->data = ch;
        CreateBiTree(fp, &(*T)->lchild);
        CreateBiTree(fp, &(*T)->rchild);
    }

    return ;
}

//Length
int BiTreeLength(BiTree T);

//Depth
int BiTreeDepth(BiTree T){
    int LD, RD;
    if(!T) return 0;
    else{
        LD = BiTreeDepth(T->lchild);
        RD = BiTreeDepth(T->rchild);
        return (LD>=RD?LD:RD)+1;
    }
}



//insert node
bool PrintTree(BiTree T)
{
	int row, col;
	int i, j, m, l, r;
	BiNode a[100][100] = {};					//用一个足够大的矩阵按原样存储树 
	
	if(T)
	{
		row = BiTreeDepth(T);					//总行数
		col = pow(2, row) - 1;					//总列数
		
		for(i=1; i<=row-1; i++)
		{
			for(j=1; j<=pow(2, i-1); j++)
			{
				m = (2*j-1)*pow(2, row-i);		//当前行结点相对位序 
				l = (4*j-3)*pow(2, row-i-1);	//下一行结点相对位序 
				r = (4*j-1)*pow(2, row-i-1);
				
				if(i==1)						//初始化 
					a[i][m] = *T;
				
				if(a[i][m].lchild)				//下一行 
					a[i+1][l] = *(a[i][m].lchild);
					
				if(a[i][m].rchild)				//下一行 
					a[i+1][r] = *(a[i][m].rchild);
			} 
		}
		
		for(i=1; i<=row; i++)
		{
			for(j=1; j<=col; j++)
			{
				if(a[i][j].data)
					printf("%c", a[i][j].data);
				else
					printf(" ");
			}
			printf("\n");
		}
	}
    return true;
} 


BiNode *LocationBiTree(BiTree T, BiNode e){
    return ;
}


//PreOrder
void PreOrder(BiTree T){
    if(!T) return ;
    else{
        printf("%c ", T->data);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

//InOrder
void InOrder(BiTree T){
    if(!T) return ;
    else{
        PreOrder(T->lchild);
        printf("%c ", T->data);
        PreOrder(T->rchild);
    }
}

//PostOrder
void PostOrder(BiTree T){
    if(!T) return ;
    else{
        PreOrder(T->lchild);
        PreOrder(T->rchild);
        printf("%c ", T->data);
    }
}

//LevelOrder
void LevelOrder(BiTree T){
    Queue Q;
    InitQueue(&Q);
    BiNode *p;
    EnQueue(&Q, &T);
    while(!QueueEmpty(Q)){
        DeQueue(&Q, &p);
        printf("%c ", p->data);
        if(p->lchild) EnQueue(&Q, p->lchild);
        if(p->rchild) EnQueue(&Q, p->rchild);
    }
}



/*Stack*/
//Init Stack
void InitStack(Stack *S){
    S->top = -1;
}


//Wheather the stack is empty
bool StackEmpty(Stack S){
    return (S.top == -1) ? true:false;
}


//Push
bool Push(Stack *S, BiNode x){
    if(S->top == MaxSize) 
        return false;
    S->data[++S->top] = x;
    return true;
}


//Pop
bool Pop(Stack *S, BiNode *x){
    if(S->top == -1)
        return false;
    *x = S->data[S->top--];
    return true;
}


//Get top data
bool GetTop(Stack S, BiNode *x){
    if(S.top == -1)
        return false;
    *x = S.data[S.top];
    return true;
}





/*Queue*/;

//Init Queue
void InitQueue(Queue *Q){
    Q->front = Q->rear = 0;
}


//Wheather queue is empty
bool QueueEmpty(Queue Q){
    if(Q.rear == Q.front) 
        return true;
    else
        return false;
}


//Wheather queue is full
bool QueueFull(Queue Q){
    if((Q.rear+1)%MaxSize == Q.front)
        return true;
    else
        return false;
}


//EnQueue
bool EnQueue(Queue *Q, BiNode *x){
    if(QueueFull(*Q))
        return false;
    Q->data[Q->rear] = x;
    Q->rear = (Q->rear + 1)%MaxSize;
    return true;
}


//DeQueue
bool DeQueue(Queue *Q, BiNode *x){
    if(QueueEmpty(*Q))
        return false;
    *x = Q->data[Q->front];
    Q->front = (Q->front + 1)%MaxSize;
    return true;
}