//
//  T_01.c
//  Data_Structure
//
//  Created by CC on 2021/3/4.
//  Copyright © 2021 CC. All rights reserved.
//

//若希望循环队列中的元素都能得到利用，则需设置一个标志域tag,
//并以tag的值为0或1来区分队头指针front和队尾指针相同时的队列状态是"空"还是"满"。
//试编写与此结构相应的入队和出队算法。

#include <stdio.h>
#include <assert.h>

#define MaxSize 8
#define ElemType int

typedef struct{
   ElemType data[MaxSize];
   int rear;
   int front;
   int tag ;
}SqQueue;

void InitQueue(SqQueue * pQ){
   assert(pQ);
   pQ->rear = 0;
   pQ->front = 0;
   pQ->tag = 0;
}

int IsEmpty(SqQueue * pQ){
   assert(pQ);
   return (pQ->rear == pQ->front && pQ->tag == 0) ? 1 : 0;
}

int EnQueue(SqQueue * pQ,ElemType x){
   assert(pQ);
   if(pQ->rear == pQ->front && pQ->tag == 1){//满了
       return 0;
   }
   pQ->data[pQ->rear] = x;
   pQ->rear = (pQ->rear + 1) %MaxSize;
   pQ->tag = 1;
   return 1;
}

int DeQueue(SqQueue * pQ,ElemType *x){
   assert(pQ);
   if( pQ->rear == pQ->front && pQ->tag == 0){
       return 0;
   }
   *x = pQ->data[pQ->front];
   pQ->front = (pQ->front + 1) %MaxSize;
   pQ->tag = 0;
   return 1;
}

void test1(){
   ElemType arr[] = {1,2,3,4,5,6,7,8,9};
   int sz = sizeof(arr)/sizeof(arr[0]);
   int i = 0;
   int x = 0;
   SqQueue q;
   SqQueue * pQ = &q;
   InitQueue(pQ);
   for(i = 0; i < sz; i++){
       if(EnQueue(pQ,arr[i])){
           printf("EnQueue succ: %d\n", arr[i]);
       }else{
           printf("EnQueue fail: %d\n", arr[i]);
       }
   }
   
   for(i = 0; i < sz; i++){
          if(DeQueue(pQ,&x)){
              printf("DeQueue succ: %d\n", x);
          }else{
              printf("DeQueue fail\n");
          }
   }
}

int main(){
   test1();
   return 0;
}
