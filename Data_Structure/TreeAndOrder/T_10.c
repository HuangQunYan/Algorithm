//
//  T_10.c
//  Data_Structure
//
//  Created by CC on 2021/3/8.
//  Copyright © 2021 CC. All rights reserved.
//

//10.假设二叉树采用二叉链表存储结构存储，设计一个算法，求先序遍序序列中第k个( 1<= k <=二叉树结点个数)个结点的值

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

    //假设队列空间足够大
int returnKthVal(BiTree * T,int k){
    Stack stack={{0},-1};
    BiTNode * pBN = T;
    int cur = 0;
    while(pBN != NULL || stack.top != -1){
        if(pBN != NULL){
            //visit(pBN);
            stack.data[++stack.top] = pBN;
            cur++;
            if(cur == k){
                return pBN->data;
            }
            pBN = pBN->lchild;
            continue;
        }
        pBN = stack.data[stack.top--];
        pBN = pBN->rchild;
    }
    return -1;
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

    printf("k = 0,val = %d\n", returnKthVal(&N1,0));
    printf("k = 1,val = %d\n", returnKthVal(&N1,1));
    printf("k = 2,val = %d\n", returnKthVal(&N1,2));
    printf("k = 3,val = %d\n", returnKthVal(&N1,3));
    printf("k = 4,val = %d\n", returnKthVal(&N1,4));
    printf("k = 5,val = %d\n", returnKthVal(&N1,5));
    printf("k = 6,val = %d\n", returnKthVal(&N1,6));
    printf("k = 7,val = %d\n", returnKthVal(&N1,7));
    printf("\n");
}

int main(){
    test1();
    return 0;
}
