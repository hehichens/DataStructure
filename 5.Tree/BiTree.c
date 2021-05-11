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

    printf("%c\n", T->data);
    printf("%c\n", T->lchild->data);
    printf("%c\n", T->rchild->data);

    int depth = BiTreeDepth(T);
    printf("Depth=%d\n", depth);

    PreOrder(T);
    printf("\n");

    InOrder(T);
    printf("\n");

    PostOrder(T);
    printf("\n");

    LevelOrder(T);
    printf("\n");

    PrintTree(T);

    return 0;
}