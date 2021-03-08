//
//  LinkQueue.c
//  Data_Structure
//
//  Created by CC on 2021/3/6.
//  Copyright © 2021 CC. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int ElemType;

typedef struct Node{
    ElemType data;
    struct Node * next;
}Node;

 //插尾法，删头法
typedef struct {
    Node * head; //头结点,出队的是head->next;
    Node * rear;
}Queue;

void queueDestroy(Queue * pQ){
    assert(pQ);
    assert(pQ->head);
    Node * p = pQ->head;
    Node * p1 = NULL;
    while(p){
        p1 = p->next;
        p->next = NULL;
        free(p);
        p = p1;
    }
    free(pQ);
}

void static queueDisplay(Queue * pQ){
    assert(pQ);
    assert(pQ->head);
    Node * p = pQ->head->next;
    while(p){
        printf(" %d ->", p->data);
        p = p->next;
    }
    printf("\n");
}

Queue * queueCreate(){
    //建立头结点
    Queue * pQ = (Queue *)malloc(sizeof(Queue));
    
    Node * pHead = (Node*)malloc(sizeof(Node));
    pHead->next = NULL;
    
    pQ->head = pQ->rear = pHead;
    return pQ;
}

int isEmpty(Queue *pQ){
    return pQ->head == pQ->rear ? 1:0;
}

void enQueue(Queue * pQ,ElemType x){
    assert(pQ);
    assert(pQ->rear);
    
    Node * newN = (Node *)malloc(sizeof(Node));
    newN->data =x;
    newN->next = NULL;
    
    pQ->rear->next = newN;
    pQ->rear = newN;
}

int deQueue(Queue *pQ,ElemType * x){
    assert(pQ);
    assert(pQ->head);
    if(pQ->head == pQ->rear){
        return 0;
    }
    Node * p = pQ->head->next;
    pQ->head->next = p->next;
    if(p == pQ->rear){
        pQ->rear = pQ->head;
    }
    *x = p->data;
    free(p);
    return 1;
}
