//
//  LinkList.c
//  Data_Structure
//
//  Created by CC on 2021/3/5.
//  Copyright © 2021 CC. All rights reserved.
//
//
//#include <stdio.h>
//#include <assert.h>
//#include <stdlib.h>

//链栈
//插头法 删头法

typedef char ElemType;

typedef struct Node{
    ElemType data;
    struct Node * next;
}Node;

typedef struct{
    Node * head;
}Stack;

Stack * create(){
    Stack * pStack= (Stack *)malloc(sizeof(Stack));
    
    Node * phead = (Node *)malloc(sizeof(Node));
    phead->next = NULL;
    
    pStack->head = phead;
    return pStack;
}


//清除pStack内用malloc 申请的资源
int destroy(Stack * pStack){
    Node * p1 = pStack->head;
    Node * p2 = NULL;
    while(p1){
        p2 = p1->next;
        p1->next = NULL;
        free(p1);
        p1 = p2;
    }
    free(pStack);
    return 1;
}

int isEmpty(Stack * pStack){
    assert(pStack);
    assert(pStack->head);
    return pStack->head->next == NULL ? 1:0;
}

// 因为用的是链表，几乎不会有push不成功的
int push(Stack * pStack,ElemType x){
    assert(pStack);
    assert(pStack->head);
    //新加结点
    Node * p = (Node *)malloc(sizeof(Node));
    //初始化
    p->data = x;
    p->next = NULL;
    //入栈
    p->next = pStack->head->next;
    pStack->head->next = p;
    return 1;
}

// return{0,1} , 0-没有数据,pop失败，1-pop成功
int pop(Stack * pStack,ElemType * x){
    assert(pStack);
    assert(pStack->head);
    Node * p = pStack->head->next;
    if(p != NULL){
        *x = p->data;
        pStack->head->next = p->next;
        p->next = NULL;
        free(p);
        return 1;
    }
    return 0;
}

