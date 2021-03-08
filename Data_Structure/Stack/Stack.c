//
//  Stack.c
//  Data_Structure
//
//  Created by CC on 2021/3/3.
//  Copyright © 2021 CC. All rights reserved.
//

#include <stdio.h>

//#define MaxSize 50
//typedef int ElemType;
//
//typedef struct{
//    ElemType data[MaxSize];
//    int top;
//}SqStack;
//
//void InitStack(SqStack * ps){
//    ps->top = -1;
//}
//
//int StackEmpty(SqStack * ps){
//    return ps->top == -1;
//}
//
//int Push(SqStack * ps , ElemType x){
//    if(ps->top == MaxSize -1){
//        return 0;
//    }
//    ps->data[++ps->top] = x;
//    return 1;
//}
//
//int Pop(SqStack *ps, ElemType * x){
//    if(ps->top == -1){
//        return 0;
//    }
//    *x = ps->data[ps->top--];
//    return 1;
//}
//
//int getTop(SqStack *ps, ElemType * x){
//    if(ps->top == -1){
//        return 0;
//    }
//    *x = ps->data[ps->top];
//    return 1;
//}
//

//or

//typedef int ElemType;
//
////头插法,有头结点
//typedef struct Node{
//    ElemType data;
//    struct Node * next;
//}Node,LStack; //链栈
//
//void InitStack(LStack * pps){
//    pps->next = NULL;
//}
//
//int StackEmpty(LStack * ps){
//    return (ps->next)? 0: 1;
//}
//
//int Push(LStack * ps , ElemType x){
//    Node newN = {x,NULL};
//    newN.next = ps->next;
//    ps->next = &newN;
//    return 1;
//}
//
//int Pop(LStack *ps, ElemType * x){
//    if(ps->next == NULL){
//        return 0;
//    }
//    Node * nd = ps->next;
//    ps->next = nd->next;
//    *x = nd->data;
//    return 1;
//}
//
//int getTop(LStack *ps, ElemType * x){
//    if(ps->next == NULL){
//        return 0;
//    }
//    *x = ps->next->data;
//    return 1;
//}
