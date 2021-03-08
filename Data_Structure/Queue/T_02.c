//
//  T_02.c
//  Data_Structure
//
//  Created by CC on 2021/3/4.
//  Copyright © 2021 CC. All rights reserved.
//


//Q是一个队列，S是一个空栈，实现将队列中的元素逆置的算法；

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef  int  ElemType;

typedef struct Node{
   ElemType data;
   struct Node * next;
}Node;

   //尾插法和删头法
typedef struct {
   Node * head;//头结点
   Node * tail;
}Queue;

   //头插法和删头法
typedef struct{
   Node * head; //头结点
}Stack;

static void initQueue(Queue * pQ){
   assert(pQ);
   pQ->head = pQ->tail = (Node *)malloc(sizeof(Node));
}

static void initStack(Stack * pS){
   assert(pS);
   pS->head = (Node *)malloc(sizeof(Node));
}

static void release(Node * pN){
   Node * pT = NULL;
   while(pN){
       pT = pN->next;
       free(pN);
       pN = pT;
   }
}

static void releaseQueue(Queue * pQ, int Qneed){
   assert(pQ);
   release(pQ->head);
   if(Qneed){
       free(pQ);
   }
}

static void releaseStack(Stack * pS,int Sneed){
   assert(pS);
   release(pS->head);
   if(Sneed){
       free(pS);
   }
}

  //插头法
static int push(Stack * pS, Node * pN){
   assert(pS);
   assert(pS->head);
   pN->next = pS->head->next;
   pS->head->next = pN;
   return 1;
}
  //删头法
static int pop(Stack * pS, Node ** ppN){
   assert(pS);
   assert(pS->head);
   Node * pT = pS->head->next;
   if(pT == NULL){
       return 0;
   }
   pS->head->next = pT->next;
   pT->next = NULL;
   *ppN = pT;
   return 1;
}

  //插尾法
static int enQueue(Queue * pQ, Node * pN){
   assert(pQ);
   assert(pQ->tail);
   pN->next = NULL;
   pQ->tail->next = pN;
   pQ->tail = pN;
   return 1;
}
  //删头法
static int deQueue(Queue * pQ, Node ** ppN){
   assert(pQ);
   assert(pQ->head);
   Node * pT = pQ->head->next;
   if(pT == NULL){
       return 0;
   }
   if(pT->next == NULL){
       pQ->tail = pQ->head;
   }
   pQ->head->next = pT->next;
   pT->next = NULL;
   *ppN = pT;
   return 1;
}

static void display(Queue * pQ){
   assert(pQ);
   assert(pQ->head);
   Node * pN = pQ->head->next;
   while(pN){
       printf(" %d ->", pN->data);
       pN = pN->next;
   }
}

static void test1(){
   ElemType arr[] = {1,2,3};
   int sz = sizeof(arr)/sizeof(arr[0]);
   int i = 0;

   Queue * pQ = (Queue *)malloc(sizeof(Queue));
   pQ->head = NULL;
   pQ->tail = NULL;
   initQueue(pQ);
   
   Stack * pS = (Stack *)malloc(sizeof(Stack));
   pS->head = NULL;
   initStack(pS);
   
   Node * pN;
   for(i = 0; i < sz ; i++){
       pN = (Node*)malloc(sizeof(Node));
       pN ->next = NULL;
       pN ->data = arr[i];
       enQueue(pQ, pN);
   }
   
   display(pQ);
   while(deQueue(pQ, &pN)){
       push(pS, pN);
   }
   
   while(pop(pS, &pN)){
       enQueue(pQ, pN);
   }
   display(pQ);
   
   releaseQueue(pQ, 1);
   releaseStack(pS, 1);
   
   
}

int main(){
   test1();
   return 0;
}
