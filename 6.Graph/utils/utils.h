/*
utils
edit by hichens
*/


#ifndef __GRAPH__UTILS__C__
#define __GRAPH__UTILS__C__

#include<stdio.h>
#include<stdlib.h>
#define MaxVertexNum 100
typedef char VertexType;
typedef int InfoType;
typedef int EdgeType;
#define INFINITY 0x7fffffff
#define bool short
#define true 1
#define false 0

// Hyper 
bool visited[MaxVertexNum];

typedef struct{
    VertexType Vex[MaxVertexNum];
    EdgeType Edge[MaxVertexNum][MaxVertexNum];
    InfoType info; //0-有向图，1-有向网（带权值），2-无向图，3-无向网（带权值）
    int vexnum, arcnum;
}MGraph;


typedef struct ArcNode{
    int adjvex;
    struct ArcNode *next;
}ArcNode;


typedef struct VNode{
    VertexType data;
    ArcNode *first;
}VNode, AdjList[MaxVertexNum];


typedef struct{
    AdjList vertices;
    int vexnum, arcnum;
    InfoType info; //0-有向图，1-有向网（带权值），2-无向图，3-无向网（带权值）
}ALGraph;

/*Mgraph*/
bool CreateGraph(FILE *fp, MGraph *G);
bool CreateDG_M(FILE *fp, MGraph *G);
bool CreateDN_M(FILE *fp, MGraph *G);
bool CreateUDG_M(FILE *fp, MGraph *G);
bool CreateUDN_M(FILE *fp, MGraph *G);
int LocateVex(MGraph G, VertexType x);

//Wheather <x, y> or (x, y) is existed.
bool Adjacent(MGraph G, VertexType x, VertexType y);

//All of the neighbor edges of x
bool Neighbors(MGraph G, VertexType x);

bool InsertVertex(MGraph G, VertexType x);

bool DeleteVertex(MGraph G, VertexType x);

//Add edge between x and y
bool AddEdge(MGraph G, VertexType x, VertexType y);

//Remove edge between x and y
bool RemoveEdge(MGraph G, VertexType x, VertexType y);

//The first neighbor edge of x
int FirstNeighbor(MGraph G, int x);

//The next neighbor vertex
int NextNeighbor(MGraph G, int x, int y);

EdgeType GetEdgeValue(MGraph G, VertexType x, VertexType y);

EdgeType SetEdgeValue(MGraph G, VertexType x, VertexType y, EdgeType v);

bool PrintGraph(MGraph G);

bool BFSTraverse(MGraph G);

void BFS(MGraph G, int v);

bool DFSTraverse(MGraph G);

void DFS(MGraph G, int v);

//DFS with Stack
bool DFSTraverse2(MGraph G);

#endif