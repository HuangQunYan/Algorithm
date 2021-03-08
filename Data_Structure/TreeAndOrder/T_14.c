//
//  T_14.c
//  Data_Structure
//
//  Created by CC on 2021/3/8.
//  Copyright © 2021 CC. All rights reserved.
//

//假设二叉树采用二叉链表存储结构，设计一个算法，求非空二叉树b的空度（即具有结点数最多的那一层的结点个数).

#include <stdio.h>

#define MaxSize 50

typedef struct BiTNode{
    int data;
    struct BiTNode * lchild, * rchild;
}BiTNode, BiTree;

typedef struct{
    BiTNode * data[MaxSize];
    int front;
    int rear;
}Queue;

     //假设Queue足够大
int T_14(BiTree * T){
    if(T == NULL){
        return 0;
    }
    int maxWidth = 1; //最大长度，预设是第一层结点数点
    int nextWidth = 0; //下一层的结点数点
    Queue queue = {{0},0,0}; //队列，假设不超过大小，当前也可以用链表
    queue.data[queue.rear++] = T;
    BiTNode * levelLast = T; //本层最后一个
    BiTNode * p = NULL; //最近从队列中取出的指针
    
    while(queue.front != queue.rear){
        p = queue.data[queue.front];
        queue.front = (queue.front + 1) % MaxSize;
        
        if(p->lchild != NULL){
            queue.data[queue.rear] = p->lchild;
            queue.rear = (queue.rear + 1) % MaxSize;
        }
        if(p->rchild != NULL){
            queue.data[queue.rear] = p->rchild;
            queue.rear = (queue.rear + 1) % MaxSize;
        }
        if(p == levelLast){
            nextWidth = (queue.rear + MaxSize - queue.front) % MaxSize;
            if(nextWidth > maxWidth){
                maxWidth = nextWidth;
            }
            levelLast = queue.data[(queue.rear - 1 + MaxSize) % MaxSize];
        }
    }
    return maxWidth;
}

void test0(){
    BiTNode N1 = {1,NULL,NULL};
    BiTNode N2 = {2,NULL,NULL};
    BiTNode N3 = {3,NULL,NULL};
    BiTNode N4 = {4,NULL,NULL};
    BiTNode N5 = {5,NULL,NULL};
    BiTNode N6 = {6,NULL,NULL};
    BiTNode N7 = {7,NULL,NULL};

    N1.lchild = &N2;
    N1.rchild = &N3;

    N2.lchild = &N4;
    N2.rchild = &N5;

    N3.lchild = &N6;
    N3.rchild = &N7;

    printf("%d\n", T_14(&N1));
}


int main(){
    test0();
    return 0;
}
