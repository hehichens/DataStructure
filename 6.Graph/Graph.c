/*

*/

#include<stdio.h>
#include "./utils/utils.c"


void Test_BFS(MGraph G){
    printf("BFS Traverse==>");
    BFSTraverse(G);
}

void Test_DFS(MGraph G){
    printf("DFS Traverse==>");
    DFSTraverse(G);
    printf("DFS Traverse==>");
    DFSTraverse2(G);
}


void Test_Create(){
    FILE *fp;
    MGraph G;
    int k;
    
    fp = fopen("./data/UDG_M.txt", "r");
    printf("Undirected Graph...\n");
    CreateGraph(fp, &G);
    PrintGraph(G);
    Test_BFS(G);
    Test_DFS(G);

    printf("\n=====================\n\n");

    fp = fopen("./data/DG_M.txt", "r");
    printf("Directed Graph...\n");
    CreateGraph(fp, &G);
    PrintGraph(G);
    Test_BFS(G);
    Test_DFS(G);

    printf("\n=====================\n\n");

    fp = fopen("./data/DN_M.txt", "r");
    printf("Directed Network...\n");
    CreateGraph(fp, &G);
    PrintGraph(G);
    Test_BFS(G);
    Test_DFS(G);

    printf("\n=====================\n\n");

    fp = fopen("./data/UDN_M.txt", "r");
    printf("Undirected Network...\n");
    CreateGraph(fp, &G);
    PrintGraph(G);
    Test_BFS(G);
    Test_DFS(G);

}





int main(){
    Test_Create();
    // Test_BFS();
    return 0;
}