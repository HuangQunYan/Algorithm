//
//  T_05.c
//  Data_Structure
//
//  Created by CC on 2021/3/7.
//  Copyright © 2021 CC. All rights reserved.
//

//假设二叉树采用二叉链表存储结构，设计一个非递归算法求二叉树的高度。

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

void visit(BiTNode * pTN){
    printf("%d " , pTN->data);
}

int lengthOfTree(BiTree * T){
    int maxLen = 0;
    Stack stack = {{},-1};
    BiTNode * pTN = T;
    BiTNode * lastVisit = NULL;
    while(pTN != NULL || stack.top != -1){
        if(pTN != NULL){ //pTN不为空时
            stack.data[++stack.top] = pTN;
            pTN = pTN->lchild;
            continue;
        }
        //pTN为空时
        pTN = stack.data[stack.top--]; //拿出最顶上的出来看看
        if(pTN->rchild == NULL || lastVisit == pTN->rchild){
            if(stack.top + 1 + 1 > maxLen){
                maxLen = stack.top + 1 + 1;
            }
            visit(pTN);
            lastVisit = pTN;
            pTN = NULL;
        }else{//pTN->rchild != NULL
            stack.data[++stack.top] = pTN;
            pTN = pTN->rchild;
        }
    }
    return maxLen;
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

    int length = lengthOfTree(&N1);
    printf("length = %d \n",length);
}



int main(){
    test1();
    return 0;
}
