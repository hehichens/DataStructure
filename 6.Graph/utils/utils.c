/*
utils
edit by hichens
*/

#include "utils.h"
#include "../../3.Stack&Queue/utils/utils.c"

/*Mgraph*/
bool CreateGraph(FILE *fp, MGraph *G){
    fscanf(fp, "%d", &(*G).info);
    char tmp;
    fscanf(fp, "%c", &tmp);

    switch ((*G).info)
    {
    case 0:
        return CreateDG_M(fp, G);
    case 1:
        return CreateDN_M(fp, G);
    case 2:
        return CreateUDG_M(fp, G);
    case 3:
        return CreateUDN_M(fp, G);
    default:
        return false;
    }
    return false;
}

bool CreateDG_M(FILE *fp, MGraph *G){
    int i, j, k;
    VertexType v1, v2;
    char tmp;
    fscanf(fp, "%d", &(*G).vexnum);
    fscanf(fp, "%c", &tmp);
    fscanf(fp, "%d", &(*G).arcnum);
    fscanf(fp, "%c", &tmp);

    for(int i = 0; i < (*G).vexnum; ++i){
        fscanf(fp, "%c", &(*G).Vex[i]);
        fscanf(fp, "%c", &tmp);
    }
    
    for(int i = 0; i < (*G).vexnum; ++i){
        for(int j = 0; j < (*G).vexnum; ++j)
            (*G).Edge[i][j] = 0;
    }

    for(int k = 0; k < (*G).arcnum; ++k){
        fscanf(fp, "%c%c", &v1, &v2);
        fscanf(fp, "%c", &tmp);
        int i = LocateVex(*G, v1);
        int j = LocateVex(*G, v2);
        if(i==-1 || j == -1) return false;

        (*G).Edge[i][j] = 1;
    }
    return true;
        
}


bool CreateDN_M(FILE *fp, MGraph *G){
    int i, j, k;
    VertexType v1, v2;
    char tmp;
    fscanf(fp, "%d", &(*G).vexnum);
    fscanf(fp, "%c", &tmp);
    fscanf(fp, "%d", &(*G).arcnum);
    fscanf(fp, "%c", &tmp);

    for(int i = 0; i < (*G).vexnum; ++i){
        fscanf(fp, "%c", &(*G).Vex[i]);
        fscanf(fp, "%c", &tmp);
    }
    
    for(int i = 0; i < (*G).vexnum; ++i){
        for(int j = 0; j < (*G).vexnum; ++j)
            (*G).Edge[i][j] = INFINITY;
    }

    for(int k = 0; k < (*G).arcnum; ++k){
        EdgeType weight;
        fscanf(fp, "%c%c%d", &v1, &v2, &weight);
        // printf("%c-%c ", v1, v2);
        fscanf(fp, "%c", &tmp);
        int i = LocateVex(*G, v1);
        int j = LocateVex(*G, v2);
        if(i==-1 || j == -1) return false;

        (*G).Edge[i][j] = weight;
    }
    return true;
}


bool CreateUDG_M(FILE *fp, MGraph *G){
    int i, j, k;
    VertexType v1, v2;
    char tmp;
    fscanf(fp, "%d", &(*G).vexnum);
    fscanf(fp, "%c", &tmp);
    fscanf(fp, "%d", &(*G).arcnum);
    fscanf(fp, "%c", &tmp);

    for(int i = 0; i < (*G).vexnum; ++i){
        fscanf(fp, "%c", &(*G).Vex[i]);
        fscanf(fp, "%c", &tmp);
    }
    
    for(int i = 0; i < (*G).vexnum; ++i){
        for(int j = 0; j < (*G).vexnum; ++j)
            (*G).Edge[i][j] = 0;
    }

    for(int k = 0; k < (*G).arcnum; ++k){
        fscanf(fp, "%c%c", &v1, &v2);
        fscanf(fp, "%c", &tmp);
        int i = LocateVex(*G, v1);
        int j = LocateVex(*G, v2);
        if(i==-1 || j == -1) return false;

        (*G).Edge[i][j] = 1;
        (*G).Edge[j][i] = 1;
    }
    return true;
        
}


bool CreateUDN_M(FILE *fp, MGraph *G){
    int i, j, k;
    VertexType v1, v2;
    char tmp;
    fscanf(fp, "%d", &(*G).vexnum);
    fscanf(fp, "%c", &tmp);
    fscanf(fp, "%d", &(*G).arcnum);
    fscanf(fp, "%c", &tmp);

    for(int i = 0; i < (*G).vexnum; ++i){
        fscanf(fp, "%c", &(*G).Vex[i]);
        fscanf(fp, "%c", &tmp);
    }
    
    for(int i = 0; i < (*G).vexnum; ++i){
        for(int j = 0; j < (*G).vexnum; ++j)
            (*G).Edge[i][j] = INFINITY;
    }

    for(int k = 0; k < (*G).arcnum; ++k){
        EdgeType weight;
        fscanf(fp, "%c%c%d", &v1, &v2, &weight);
        // printf("%c-%c ", v1, v2);
        fscanf(fp, "%c", &tmp);
        int i = LocateVex(*G, v1);
        int j = LocateVex(*G, v2);
        if(i==-1 || j == -1) return false;

        (*G).Edge[i][j] = weight;
        (*G).Edge[j][i] = weight;
    }
    return true;
}


int LocateVex(MGraph G, VertexType x){
    for(int i = 0; i < G.vexnum; ++i)
        if(G.Vex[i] == x)
            return i;

    return -1;
}


bool Adjacent(MGraph G, VertexType x, VertexType y);

bool Neighbors(MGraph G, VertexType x);

bool InsertVertex(MGraph G, VertexType x);

bool DeleteVertex(MGraph G, VertexType x);

bool AddEdge(MGraph G, VertexType x, VertexType y);

bool RemoveEdge(MGraph G, VertexType x, VertexType y);


//The first neighbor edge of x
int FirstNeighbor(MGraph G, int x){
    int k, t;
    k = LocateVex(G, G.Vex[x]);
    if(k != -1){
        if(G.info % 2)
            t = INFINITY;
        else
            t = 0;
        for(int j = 0; j < G.vexnum; ++j)
            if(G.Edge[k][j] != t)
                return j;
    }
    return -1;
}


int NextNeighbor(MGraph G, int x, int y){
    int k1, k2, t;
    k1 = LocateVex(G, G.Vex[x]);
    k2 = LocateVex(G, G.Vex[y]);
    if(k1 != -1 && k2 != -1){
        if(G.info % 2)
            t = INFINITY;
        else
            t = 0;
        for(int j = k2+1; j <= G.vexnum; ++j)
            if(G.Edge[k1][j] != t)
                return j;
    }
    return -1;
}


EdgeType GetEdgeValue(MGraph G, VertexType x, VertexType y);

EdgeType SetEdgeValue(MGraph G, VertexType x, VertexType y, EdgeType v);


bool PrintGraph(MGraph G){
    printf("  ");
    for(int i = 0; i < G.vexnum; ++i)
        printf("%2c ", G.Vex[i]);
    printf("\n");

    for(int i = 0; i < G.vexnum; ++i){
        printf("%c ",G.Vex[i]);
        for(int j = 0; j < G.vexnum; ++j){
            if(G.Edge[i][j] == INFINITY)
                printf(" ∞ ");
            else
                printf("%2d ", G.Edge[i][j]);
        }
        printf("\n");
    }
    return true;
}




bool BFSTraverse(MGraph G){
    for(int i = 0; i < G.vexnum; ++i)
        visited[i] = false;
    
    for(int i = 0; i < G.vexnum; ++i)
        if(!visited[i])
            BFS(G, i);
    printf("\n");
    return true;
}

void BFS(MGraph G, int v){
    Queue Q; InitQueue(&Q);
    if(!visited[v]){
        printf("%c ", G.Vex[v]);
        visited[v] = true;
        EnQueue(&Q, v);
        while(!QueueEmpty(Q)){
            DeQueue(&Q, &v);
            for(int w = FirstNeighbor(G, v); w >= 0; w=NextNeighbor(G, v, w)){
                if(!visited[w]){
                    printf("%c ", G.Vex[w]);
                    visited[w] = true;
                    EnQueue(&Q, w);
                }
            }
        }
    }
}


bool DFSTraverse(MGraph G){
    for(int i = 0; i < G.vexnum; ++i)
        visited[i] = false;
    
    for(int i = 0; i < G.vexnum; ++i)
        if(!visited[i])
            DFS(G, i);
    printf("\n");
    return true;
}

void DFS(MGraph G, int v){
    printf("%c ", G.Vex[v]);
    visited[v] = true;
    for(int w = FirstNeighbor(G, v); w >= 0; w=NextNeighbor(G, v, w))
        if(!visited[w])
            DFS(G, w);
}


//DFS with Stack
bool DFSTraverse2(MGraph G){
    int v=0;
    Stack S; InitStack(&S);
    for(int i = 0; i < G.vexnum; ++i)
        visited[i] = false;

    Push(&S, v);
    visited[v] = true;
    while(!StackEmpty(S)){
        Pop(&S, &v);
        printf("%c ", G.Vex[v]);
        for(int w=FirstNeighbor(G, v); w>=0; w=NextNeighbor(G, v, w)){
            if(!visited[w]){
                Push(&S, w);
                visited[w] = true;
            }
        }
    }
    printf("\n");
    return 0;
}