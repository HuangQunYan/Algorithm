//
//  T_07.c
//  Data_Structure
//
//  Created by CC on 2021/3/7.
//  Copyright © 2021 CC. All rights reserved.
//

//二叉树按二叉链表形式存储，写一个判别给定二叉树是否是完全二叉树的算法。

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
int completeBiTree(BiTree * T){
    if(T == NULL){
        return 1;
    }
    int appearNULL = 0;
    Queue queue ={{0},0,0};
    queue.data[queue.rear] = T;
    queue.rear = (queue.rear + 1) %MaxSize;
    BiTNode * pBN = NULL;
    while(queue.front != queue.rear){ //不为空
        pBN = queue.data[queue.front];
        queue.front = (queue.front + 1) % MaxSize;
        
        if(pBN->lchild != NULL){
            if(appearNULL == 1){
                return 0;
            }
            queue.data[queue.rear] = pBN->lchild;
            queue.rear = (queue.rear + 1) %MaxSize;
        }else{
            appearNULL = 1;
        }
        if(pBN->rchild != NULL){
            if(appearNULL == 1){
                return 0;
            }
            queue.data[queue.rear] = pBN->rchild;
            queue.rear = (queue.rear + 1) %MaxSize;
        }else{
            appearNULL = 1;
        }
    }
    return 1;
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
    
    int result = completeBiTree(&N1);
    printf("is complete BiTree ? %s\n" , result ? "Yes":"No");
}

void test2(){
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

    N3.rchild = &N6;
    
    int result = completeBiTree(&N1);
    printf("is complete BiTree ? %s\n" , result ? "Yes":"No");
}

void test3(){
    BiTNode N1 = {1,NULL,NULL};
    BiTNode N2 = {2,NULL,NULL};
    BiTNode N4 = {4,NULL,NULL};
    BiTNode N5 = {5,NULL,NULL};

    N1.lchild = &N2;
    
    N2.lchild = &N4;
    N2.rchild = &N5;
    
    int result = completeBiTree(&N1);
    printf("is complete BiTree ? %s\n" , result ? "Yes":"No");
}

void test4(){
    BiTNode N1 = {1,NULL,NULL};
    BiTNode N2 = {2,NULL,NULL};
    BiTNode N3 = {3,NULL,NULL};
    BiTNode N5 = {5,NULL,NULL};
    BiTNode N6 = {6,NULL,NULL};

    N1.lchild = &N2;
    N1.rchild = &N3;
    
    N2.rchild = &N5;

    N3.lchild = &N6;
    
    int result = completeBiTree(&N1);
    printf("is complete BiTree ? %s\n" , result ? "Yes":"No");
}

int main(){
    test1();
    test2();
    test3();
    test4();
    return 0;
}
