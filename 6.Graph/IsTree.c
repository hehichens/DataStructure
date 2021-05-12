/*
2.判断一个无向图是否为树。

> 使用DFS一次就访问到n个顶点和n-1条边，则是树。
*/


#include<stdio.h>
#include "./utils/utils.c"

int Vnum=0, Enum=0;

void dfs(MGraph G, int v){
    visited[v] = true;
    Vnum++;
    for(int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)){
        Enum++;
        if(!visited[w])
            dfs(G, w);
    }
}


bool Is_Tree(MGraph G){
    for(int i = 0; i < G.vexnum; ++i)
        visited[i] = false;

    dfs(G, 0);
    if(Vnum == G.vexnum && Enum == 2*(G.vexnum - 1))
        return true;
    else
        return false;
}


void Test_1(){
    FILE *fp;
    MGraph G;
    fp = fopen("./data/UDG_M1.txt", "r");
    printf("Undirected Graph...\n");
    CreateGraph(fp, &G);
    PrintGraph(G);

    if(Is_Tree(G))
        printf("Yes!\n");
    else
        printf("No!\n");
}


void Test_2(){
    FILE *fp;
    MGraph G;
    fp = fopen("./data/UDG_M.txt", "r");
    printf("Undirected Graph...\n");
    CreateGraph(fp, &G);
    PrintGraph(G);

    if(Is_Tree(G))
        printf("Yes!\n");
    else
        printf("No!\n");
}

int main(){
    Test_1();
    Test_2();
    return 0;
}