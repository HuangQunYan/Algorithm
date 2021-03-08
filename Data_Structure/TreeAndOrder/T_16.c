//
//  T_16.c
//  Data_Structure
//
//  Created by CC on 2021/3/8.
//  Copyright © 2021 CC. All rights reserved.
//

//设计一个算法将二叉树的叶结点按从左到右的顺序连成一个单链表，
//表头指针head。二叉树按二叉链表方式存储，链接时用叶结点的右指针域来存放单链表指针。

#include <stdio.h>

#define MaxSize 50

typedef struct BiTNode{
    int data;
    struct BiTNode * lchild, * rchild;
}BiTNode, BiTree;


     //一开始,head是为空
    // pre 是前继结点,一开始也为空
void T_16(BiTree * T , BiTNode ** head){
    if(T == NULL){
        return;
    }
    static BiTNode * pre = NULL;
    
    if(T->lchild == NULL && T->rchild == NULL){//是叶子
        if(*head == NULL){
            *head = T;
        }
        if(pre != NULL){
            pre->rchild = T;
        }
        pre = T;
        return;
    }
    //不是叶子
    T_16(T->lchild, head);
    T_16(T->rchild, head);
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
    //N2.rchild = &N5;

    N3.lchild = &N6;
    N3.rchild = &N7;
    
    BiTNode * head = NULL;
    
    T_16(&N1, &head);
    while(head != NULL){
        printf(" %d ->",head->data);
        head = head->rchild;
    }
    printf("\n");
}


int main(){
    test0();
    return 0;
}

