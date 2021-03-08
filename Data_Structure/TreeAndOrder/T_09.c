//
//  T_09.c
//  Data_Structure
//
//  Created by CC on 2021/3/8.
//  Copyright © 2021 CC. All rights reserved.
//

//设树B是一棵采用链式结构存储的二叉树，编写一个把树B中所有结点的左右子树进行交换的函数。

#include <stdio.h>

#define MaxSize 50

typedef struct BiTNode{
    int data;
    struct BiTNode * lchild, * rchild;
}BiTNode, BiTree;

typedef struct{
    BiTNode * data[MaxSize];
    int front,rear;
}Queue;

    //假设队列空间足够大
void exchangeLRsubTree(BiTree * T){
    if(T == NULL){
        return;
    }
    BiTNode * pTmp = T->lchild;
    T->lchild = T->rchild;
    T->rchild = pTmp;
    exchangeLRsubTree(T->lchild);
    exchangeLRsubTree(T->rchild);
}


void test1(){
    BiTNode N1 = {1,NULL,NULL};
    BiTNode N2 = {2,NULL,NULL};
    BiTNode N3 = {3,NULL,NULL};
    BiTNode N4 = {4,NULL,NULL};
    BiTNode N5 = {5,NULL,NULL};
    BiTNode N6 = {6,NULL,NULL};

    N1.lchild = &N2;
    N1.rchild = &N3;
    
    N2.lchild = &N4;
    N2.rchild = &N5;

    N3.lchild = &N6;
    
    exchangeLRsubTree(&N1);
    printf("\n");
}

void test2(){
    BiTNode N1 = {1,NULL,NULL};
    BiTNode N2 = {2,NULL,NULL};
    BiTNode N3 = {3,NULL,NULL};
    BiTNode N4 = {4,NULL,NULL};
    BiTNode N6 = {6,NULL,NULL};

    N1.lchild = &N2;
    N1.rchild = &N3;
    
    N2.lchild = &N4;

    N3.rchild = &N6;
    
    exchangeLRsubTree(&N1);
    printf("\n");
}

void test3(){
    BiTNode N1 = {1,NULL,NULL};
    BiTNode N2 = {2,NULL,NULL};
    BiTNode N4 = {4,NULL,NULL};
    BiTNode N5 = {5,NULL,NULL};

    N1.lchild = &N2;
    
    N2.lchild = &N4;
    N2.rchild = &N5;
    
    exchangeLRsubTree(&N1);
    printf("\n");
}

int main(){
    test1();
    test2();
    test3();
    return 0;
}
