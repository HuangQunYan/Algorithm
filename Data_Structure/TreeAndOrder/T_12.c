////
////  T_12.c
////  Data_Structure
////
////  Created by CC on 2021/3/8.
////  Copyright © 2021 CC. All rights reserved.
////
//
//在二叉树中查找值为x的结点，试编写算法(用C语言)打印值为x的结点的所有祖先，假设值为x的结点不多于一个.

#include <stdio.h>

#define MaxSize 50

typedef struct BiTNode{
    int data;
    struct BiTNode * lchild, * rchild;
}BiTNode, BiTree;

typedef struct{
    BiTNode * data[MaxSize];
    int top;
}Stack;

    //假设栈的空间足够大,实际上可用链栈
    //后序非递归方式
void printAncestor(BiTree * T,int x){
    Stack stack = {{0},-1};
    //先找出x;
    BiTNode * p = T;
    BiTNode * lastVisit = NULL;
    while(p != NULL || stack.top != -1){
        if(p != NULL){
            if(p->data == x){
                break;
            }
            stack.data[++ stack.top] = p;
            p = p->lchild;
            continue;
        }
        //p为NULL时
        p = stack.data[stack.top--];
        if(p->rchild == NULL || p->rchild == lastVisit){
           // visit(p);
            lastVisit = p;
            p = NULL;
        }else{//p->rchild != NULL && p->rchild != lastVisit
            stack.data[++stack.top] = p;
            p = p->rchild;
        }
    }
    //打印祖先
    while(stack.top != -1){
        p = stack.data[stack.top--];
        printf(" %d ,", p->data);
    }
}

void test0(int x){
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

    printf("ansestor: ");
    printAncestor(&N1, x);
    printf("\n");
}

void test1(){
    test0(1);
}

void test2(){
    test0(2);
}

void test3(){
    test0(3);
}

void test4(){
    test0(4);
}

void test5(){
    test0(5);
}

void test6(){
    test0(6);
}

int main(){
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    return 0;
}
