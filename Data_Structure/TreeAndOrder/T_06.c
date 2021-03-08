//
//  T_06.c
//  Data_Structure
//
//  Created by CC on 2021/3/7.
//  Copyright © 2021 CC. All rights reserved.
//

//设一棵二叉树中各结点的值互不相同，其先序遍历序列和中序遍序序列分别存于两个一维数组A[1,..,n]和B[1,...,n]
//试编写算法建立二叉树的二叉链表。

#include <stdio.h>
#include <stdlib.h>


typedef struct BiNode{
    int data;
    struct BiNode * lchild, * rchild;
}BiNode,BiTree;

BiNode * _create(int A[],int B[],int a_end,int b_start, int b_end){
    static int a_start = 0;
    
    if(a_start > a_end || b_start > b_end){
        return NULL;
    }
    BiNode * T = (BiNode *)malloc(sizeof(BiNode));
    T->data = A[a_start];
    int i = 0;
    for(i = b_start; i <= b_end; i++){
        if(B[i] == A[a_start]){
            break;
        }
    }
    a_start++;
    //用B中下标为i的左边数据去构建T的左边
    T->lchild = _create(A, B , a_end, b_start, i-1);
    //用B中下票为i的右边数据去构建T的右边
    T->rchild = _create(A, B , a_end, i+1, b_end);
    return T;
    
}

//先序遍历 A ，中序遍历B
BiTree * biTreeCreate(int A[],int B[],int sz){
    return _create(A,B,sz -1,0,sz-1);
}

void biTreeDestroy(BiTree * T){
    if(T != NULL){
        biTreeDestroy(T->lchild);
        biTreeDestroy(T->rchild);
        free(T);
    }
}

void visit(BiTree * T){
    printf("%d,", T->data);
}

void PreOrder(BiTree * T){
    if(T != NULL){
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

void InOrder(BiTree * T){
    if(T != NULL){
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}

void test1(){
    int A[] = {1,2,4,6,3,5};
    int B[] = {2,6,4,1,3,5};
    int sz = sizeof(A)/sizeof(A[0]);
    BiTree * T = biTreeCreate(A,B,sz);
    PreOrder(T);
    printf("\n");
    InOrder(T);
    printf("\n");
    biTreeDestroy(T);
    
}


int main(){
    test1();
    return 0;
}
