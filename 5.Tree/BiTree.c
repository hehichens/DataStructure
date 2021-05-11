/*

*/

#include<stdio.h>
#include "./utils/utils.c"


    /* Read data from file with fscanf */
    // FILE *fp;
    // char ch;
    // fp = fopen("data.txt", "r");
    // if(fp == NULL){
    //     printf("No Such File!");
    //     return 0;
    // }

    // while(fscanf(fp, "%c", &ch)==1){
    //     printf("%c ", ch);
    // }
    // printf("\n");

int main(){
    FILE *fp;
    BiTree T;
    fp = fopen("data.txt", "r");
    // data： ABDG^^^EH^^I^^CF^J^^^
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