//
//  T_04.c
//  Data_Structure
//
//  Created by CC on 2021/3/4.
//  Copyright © 2021 CC. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node{
   int data;
   struct Node * next;
}Node;

typedef struct{
   Node * front; //下一个数据取出的结点
   Node * rear;//下一个数据插入的结点
}Queue;

static void releaseQueue(Queue * pQ, int Qneed){
   Node * pNode = pQ->rear->next;
   Node * pT;
   while(pNode != pQ->rear){
       pT = pNode->next;
       free(pNode);
       pNode = pT;
   }
   free(pQ->rear);
   if(Qneed){
       free(pQ);
   }
}

void initQueue(Queue * pQ ){
   Node * node = (Node *)malloc(sizeof(Node));
   node->data = -1;
   node->next = node;
   pQ->rear = pQ->front = node;
}

void EnQueue(Queue * pQ,int x){
   pQ->rear->data = x;
   if(pQ->rear->next == pQ->front){
       Node * newN = (Node *)malloc(sizeof(Node));
       newN->data = -1;
       newN->next = pQ->rear->next;
       pQ->rear->next = newN;
   }
   pQ->rear = pQ->rear->next;
}

int DeQueue(Queue * pQ,int *x){
   if(pQ->front == pQ->rear){
       return 0;
   }
   *x = pQ->front->data;
   pQ->front = pQ->front->next;
   return 1;
}

void test1(){
   Queue * pQ = (Queue *)malloc(sizeof(Queue));
   int arr[] = {1,2,3,4,5,6};
   int sz = sizeof(arr)/sizeof(arr[0]);
   int i = 0;
   int x;

   initQueue(pQ);
   for(i = 0; i < sz; i++){
       EnQueue(pQ, arr[i]);
   }

   for(i = 0; i < sz; i++){
       DeQueue(pQ, &x);
       printf(" %d ->", x);
   }
   releaseQueue(pQ, 1);
}

int main(){
   test1();
   return 0;
}
