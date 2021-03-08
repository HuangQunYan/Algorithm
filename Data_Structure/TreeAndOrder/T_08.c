//
//  T_08.c
//  Data_Structure
//
//  Created by CC on 2021/3/8.
//  Copyright © 2021 CC. All rights reserved.
//

//假设二叉树采用二叉链表存储结构存储，试设计一个算法，计算一棵给定二叉树的所有双分支结点个数

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
int countNumsOfDualBranch(BiTree * T){
    int count = 0;
    if(T == NULL){
        return count;
    }
    Queue queue ={{0},0,0};
    queue.data[queue.rear] = T;
    queue.rear = (queue.rear + 1) %MaxSize;
    BiTNode * pBN = NULL;
    while(queue.front != queue.rear){ //不为空
        pBN = queue.data[queue.front];
        queue.front = (queue.front + 1) % MaxSize;
        
        if(pBN->lchild != NULL && pBN->rchild != NULL){
            count++;
        }
        if(pBN->lchild != NULL){
            queue.data[queue.rear] = pBN->lchild;
            queue.rear = (queue.rear + 1) %MaxSize;
        }
        if(pBN->rchild != NULL){
            queue.data[queue.rear] = pBN->rchild;
            queue.rear = (queue.rear + 1) %MaxSize;
        }
    }
    return count;
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
    
    int result = countNumsOfDualBranch(&N1);
    printf("%d\n" , result);
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
    
    int result = countNumsOfDualBranch(&N1);
    printf("%d\n" , result);
}

void test3(){
    BiTNode N1 = {1,NULL,NULL};
    BiTNode N2 = {2,NULL,NULL};
    BiTNode N4 = {4,NULL,NULL};
    BiTNode N5 = {5,NULL,NULL};

    N1.lchild = &N2;
    
    N2.lchild = &N4;
    N2.rchild = &N5;
    
    int result = countNumsOfDualBranch(&N1);
    printf("%d\n" , result);
}


int main(){
    test1();
    test2();
    test3();
    return 0;
}
