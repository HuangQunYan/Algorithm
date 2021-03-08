//
//  T_11.c
//  Data_Structure
//
//  Created by CC on 2021/3/8.
//  Copyright © 2021 CC. All rights reserved.
//

// 已知二叉树以二叉链表存储，编写算法完成：对于树中每个元素值为x的结点，删去以它为根的子树，并释放相应空间;

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50

typedef struct BiTNode{
    int data;
    struct BiTNode * lchild, * rchild;
}BiTNode, BiTree;

typedef struct{
    BiTNode * data[MaxSize];
    int top;
}Stack;

void release(BiTree * T){ //BiNode * T 没采用malloc方式，所以不用真的free
//    if(T == NULL){
//        return;
//    }
//    release(T->lchild);
//    release(T->rchild);
//    free(T);
}

    //假设队列空间足够大
BiTNode * deleteX(BiTree * T,int x){
    if(T == NULL){
        return NULL;
    }
    if(T->data == x){
        release(T);
        return NULL;
    }
    T->lchild = deleteX(T->lchild, x);
    T->rchild = deleteX(T->rchild, x);
    return T;
}

void test0(int k){
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
    
    BiTNode * result = deleteX(&N1, k);
    
    printf("\n");
}

void test1(){
    test0(1);
}

void test2(){
    test0(2);
}

void test3(){
    test0(5);
}

int main(){
    test1();
    test2();
    test3();
    return 0;
}

