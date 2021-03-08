//
//  T_04.c
//  Data_Structure
//
//  Created by CC on 2021/3/7.
//  Copyright © 2021 CC. All rights reserved.
//

//试给出二叉树的自下而上，从右到左的层次遍序算法

#include <stdio.h>

#define MaxSize  20

typedef struct BiTNode{
    int data;
    struct BiTNode * lchild, * rchild;
}BiTNode,BiTree;

typedef struct {
    BiTNode * data[MaxSize];
    int top;
}Stack;

typedef struct {
    BiTNode * data[MaxSize];
    int rear;
    int front;
}Queue;

void visit(BiTNode * pTN){
    printf("%d " , pTN->data);
}

void T_04(BiTree * T){
    Stack stack ={{},-1};
    Queue queue = {{},0,0};//假设没满
    queue.data[queue.rear++] = T;
    BiTNode * pTN;
    while(queue.rear != queue.front){
        pTN = queue.data[queue.front++];
        stack.data[++stack.top] = pTN;
        if(pTN->lchild != NULL){
            queue.data[queue.rear++] = pTN->lchild ;
        }
        if(pTN->rchild != NULL){
            queue.data[queue.rear++] = pTN->rchild;
        }
    }
    
    while(stack.top != -1){
        pTN = stack.data[stack.top--];
        visit(pTN);
    }
}

void test1(){
    BiTNode N1 = {1,NULL,NULL};
    BiTNode N2 = {2,NULL,NULL};
    BiTNode N3 = {3,NULL,NULL};
    BiTNode N4 = {4,NULL,NULL};
    BiTNode N5 = {5,NULL,NULL};
    BiTNode N6 = {6,NULL,NULL};
    
    N1.lchild = &N2;
    N2.rchild = &N4;
    N4.lchild = &N6;
    
    N1.rchild = &N3;
    N3.rchild = &N5;
    
    T_04(&N1);
    printf("\n");
}



int main(){
    test1();
    return 0;
}
