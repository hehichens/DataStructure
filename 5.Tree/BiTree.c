/*

*/

#include<stdio.h>
#include "./utils/utils.c"


int main(){
    FILE *fp;
    BiTree T;
    fp = fopen("data1.txt", "r");
    InitBiTree(&T);
    CreateBiTree(fp, &T);

    int depth = BiTreeDepth(T);

    printf("====================Tree Overall======================\n");
    PrintTree(T);
    printf("\nDepth=%d\n\n", depth);

    printf("================4 ways to travel trees==================\n");

    printf("PreOder==>");
    PreOrder(T);
    printf("\n");
    printf("PreOder2==>");
    PreOrder2(T);
    printf("\n\n");

    printf("InOrder==>");
    InOrder(T);
    printf("\n");
    printf("InOrder2==>");
    InOrder2(T);
    printf("\n\n");

    printf("PostOrder==>");
    PostOrder(T);
    printf("\n");
    printf("PostOrder2==>");
    PostOrder2(T);
    printf("\n\n");

    printf("LevelOrder==>");
    LevelOrder(T);
    printf("\n\n");
    return 0;
}