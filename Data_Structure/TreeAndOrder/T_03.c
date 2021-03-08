//
//  T_03.c
//  Data_Structure
//
//  Created by CC on 2021/3/7.
//  Copyright © 2021 CC. All rights reserved.
//

//编写后序遍序二叉树的非递归算法

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

void postOrder2(BiTree * T){
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
        pTN = stack.data[stack.top--];
        if(pTN->rchild == NULL || lastVisit == pTN->rchild){
            visit(pTN);
            lastVisit = pTN;
            pTN = NULL;
        }else{//pTN->rchild != NULL
            stack.data[++stack.top] = pTN;
            pTN = pTN->rchild;
        }
    }
}

void PostOrder(BiTree * T){
    if(T != NULL){
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
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
    
    postOrder2(&N1);
    printf("\n");
    PostOrder(&N1);
    printf("\n");
}



int main(){
    test1();
    return 0;
}
