//
//  T_01.c
//  Data_Structure
//
//  Created by CC on 2021/3/3.
//  Copyright © 2021 CC. All rights reserved.
//

#include <stdio.h>

#define MaxSize 10
#define ElemType int

typedef struct{
   ElemType data[MaxSize];
   int rear;
   int front;
}SqQueue;

void InitQueue(SqQueue * q){
   q->rear = 0;
   q->front = 0;
}

int isEmpty(SqQueue * q){
   return q->rear == q->front ? 1 : 0;
}

int EnQueue(SqQueue * q,ElemType x){
   if((q->rear + 1) % MaxSize == q->front){
       return 0;
   }
   q->data[q->rear] = x;
   q->rear = (q->rear + 1) %MaxSize;
   return 1;
}

int DeQueue(SqQueue * q,ElemType *x){
   if( q->rear == q->front){
       return 0;
   }
   *x = q->data[q->front];
   q->front = (q->front + 1) %MaxSize;
   return 1;
}
