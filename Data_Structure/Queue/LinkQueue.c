//
//  LinkQueue.c
//  Data_Structure
//
//  Created by CC on 2021/3/3.
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

typedef struct {
   Node * front;
   Node * rear;
}LinkQueue;

void release(Node * node){
   Node * p = NULL;
   while(node){
       p = node->next;
       free(node);
       node = p;
   }
}

void display(Node * node){
   while(node){
       printf(" %d ->", node->data);
       node = node->next;
   }
   printf("\n");
}

void initQueue(LinkQueue * pQ){
   //建立头结点
   pQ->front = pQ->rear = (Node*)malloc(sizeof(Node));
}

int isEmpty(LinkQueue *pQ){
   return pQ->front == pQ->rear ? 1:0;
}

void enQueue(LinkQueue * pQ,ElemType x){
   Node * newN = (Node *)malloc(sizeof(Node));
   newN->data =x;
   newN->next = NULL;
   pQ->rear->next = newN;
   pQ->rear = newN;
}

int deQueue(LinkQueue *pQ,ElemType * x){
   if(pQ->front == pQ->rear){
       return 0;
   }
   Node * p = pQ->front->next;
   pQ->front->next = p->next;
   if(p == pQ->rear){
       pQ->rear = pQ->front;
   }
   *x = p->data;
   free(p);
   return 1;
}
