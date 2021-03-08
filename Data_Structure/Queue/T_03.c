//
//  T_03.c
//  Data_Structure
//
//  Created by CC on 2021/3/4.
//  Copyright © 2021 CC. All rights reserved.
//

#include <stdio.h>

#define MaxSize 5
typedef int ElemType;

typedef struct{
   ElemType data[MaxSize];
   int top;
}SqStack;

void InitStack(SqStack * ps){
   ps->top = -1;
}

int StackEmpty(SqStack * ps){
   return ps->top == -1 ? 1: 0;
}

int Push(SqStack * ps , ElemType x){
   if(ps->top == MaxSize -1){
       return 0;
   }
   ps->data[++ps->top] = x;
   return 1;
}

int Pop(SqStack *ps, ElemType * x){
   if(ps->top == -1){
       return 0;
   }
   *x = ps->data[ps->top--];
   return 1;
}

int StackOverFlow(SqStack * ps){
   return ps->top == MaxSize -1 ? 1:0;
}

typedef struct {
   SqStack s1;
   SqStack s2;
}Queue;

void initQueue(Queue * pQ){
   InitStack(&(pQ->s1));
   InitStack(&(pQ->s2));
}

int EnQueue(Queue * pQ,ElemType x){
   SqStack * pS1 = &(pQ->s1);
   SqStack * pS2 = &(pQ->s2);
   if(!StackEmpty(pS2) ){
       ElemType tmp;
       while( Pop(pS2, &tmp) ){
           Push(pS1, tmp);
       }
   }
   if(!StackOverFlow(pS1)){
       Push(pS1, x);
       return 1;
   }
   return 0;
}

int DeQueue(Queue * pQ,ElemType *x){
   SqStack * pS1 = &(pQ->s1);
   SqStack * pS2 = &(pQ->s2);
   if(StackEmpty(pS2)){
       ElemType tmp;
       while(Pop(pS1, &tmp)){
           Push(pS2, tmp);
       }
   }
   if(!StackEmpty(pS2) ){
       Pop(pS2, x);
       return 1;
   }
   return 0;
}

int QueueEmpty(Queue * pQ){
   SqStack * pS1 = &(pQ->s1);
   SqStack * pS2 = &(pQ->s2);
   return (StackEmpty(pS1) && StackEmpty(pS2)) ? 1:0;
}


void test1(){
   int arr[] = {1,2,3,4,5,6};
   int sz = sizeof(arr)/sizeof(arr[0]);
   int i = 0;
   Queue Q;
   initQueue(&Q);
   for(i = 0; i < sz; i++){
       if(EnQueue(&Q, arr[i])){
           printf("enQueue succ : %d\n",arr[i]);
       }else{
           printf("enQueue fail : %d\n",arr[i]);
       }
   }
   int x;
   while(DeQueue(&Q, &x)){
       printf("deQueue succ : %d\n",x);
   }
}

int main(){
   test1();
   return 0;
}
