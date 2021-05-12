2.判断一个无向图是否为树。

> 使用DFS一次就访问到n个顶点和n-1条边，则是树。

```c
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
```

