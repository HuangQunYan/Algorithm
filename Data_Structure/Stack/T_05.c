//
//  T_05.c
//  Data_Structure
//
//  Created by CC on 2021/3/3.
//  Copyright © 2021 CC. All rights reserved.
//

#define MaxSize 50

#define ElemType int

#include <stdio.h>

typedef struct {
   ElemType data[MaxSize];
   int top[2];
}Stack ;

Stack stack;

int STACK_NUM_ERROR = 3;
int STACK_FULL = 1;
int STACK_EMPTY = 2;
int SUCC = 0;

int push(int i , ElemType x){
   if(i < 0 || i > 1){
       return STACK_NUM_ERROR;
   }
   if(stack.top[0] + 1 == stack.top[1]){
       return STACK_FULL;
   }
   stack.top[i] = stack.top[i] + ((i == 0)? 1:-1);
   stack.data[stack.top[i]] = x;
   return SUCC;
}

int pop(int i , ElemType *x){
   if(i < 0 || i > 1){
       return STACK_NUM_ERROR;
   }
   if(stack.top[i] == (i == 0 ? -1:MaxSize)){
       return STACK_EMPTY;
   }
   *x = stack.data[stack.top[i]];
   stack.top[i] += (i == 0 ? -1 : 1);
   return SUCC;
}
