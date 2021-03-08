//
//  T_19.c
//  Data_Structure
//
//  Created by CC on 2021/3/8.
//  Copyright © 2021 CC. All rights reserved.
//

//二叉树的带权路径长度(WRL)是二叉树中所有叶结点的带权路径长度之和。
//给定一棵二叉树，采用二叉链表存储，结点结构为left,weight,right

#include <stdio.h>
#define MaxSize 50

typedef struct BiTNode{
    int weight;
    struct BiTNode * left,* right;
}BiTNode, BiTree;

typedef struct{
    BiTNode * data[MaxSize];
    int top;
}Stack;


//设最大深度不超过50,要是担心，可以链表实现stack,多加一个长度
int WRL(BiTree * T){
    if(T == NULL){
        return 0;
    }
    int wrl = 0;
    Stack stack = {{NULL},-1};
    BiTNode * p = T;
    BiTNode * lastVisit = NULL;
    while(p != NULL || stack.top != -1){
        if(p != NULL){
            stack.data[++stack.top] = p;
            p = p->left;
            continue;
        }
        //p == NULL
        p = stack.data[stack.top--];
        if(p->right == NULL || p->right == lastVisit){
            //visit(p);
            if(p->left == NULL && p->right == NULL){
                wrl = wrl + p->weight * (stack.top + 1 + 1);
            }
            lastVisit = p;
            p = NULL;
        }else{
            stack.data[++stack.top] = p;
            p = p->right;
        }
    }
    return wrl;
}

void test0(){
    BiTNode N1 = {1,NULL,NULL};
    BiTNode N2 = {2,NULL,NULL};
    BiTNode N3 = {3,NULL,NULL};
    BiTNode N4 = {4,NULL,NULL};
    BiTNode N5 = {5,NULL,NULL};
    BiTNode N6 = {6,NULL,NULL};

    N1.left = &N2;
    N1.right = &N3;

    N2.left = &N4;
    //N2.right = &N5;

    N3.left = &N6;

    printf(" %d \n" , WRL(&N1)); //45
}


int main(){
    test0();
    return 0;
}
