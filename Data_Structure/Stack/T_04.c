//
//  T_04.c
//  Data_Structure
//
//  Created by CC on 2021/3/3.
//  Copyright © 2021 CC. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
   char data;
   struct Node * next;
}Node,LinkList;

static LinkList * genLinkList(char * str){
   LinkList * head = (LinkList *)malloc(sizeof(LinkList)); //头结点
   Node * tail = head;
   int i = 0;
   head->next = NULL;
   for(i= 0; str[i] != '\0'; i++){
       Node * nd = (Node *)malloc(sizeof(Node));
       nd -> data = str[i];
       nd->next = NULL;
       tail->next = nd;
       tail = nd;
   }
   return head;
}

void release(LinkList * ps){
   Node * nd = NULL;
   while(ps){
       nd = ps->next;
       free(ps);
       ps = nd;
   }
}

void display(LinkList * pL){
   pL = pL->next;
   while(pL){
       printf(" %c ->",pL->data);
       pL = pL->next;
   }
   printf("\n");
}

#define MaxSize 50
typedef char ElemType;

typedef struct{
   ElemType data[MaxSize];
   int top;
}SqStack;

void InitStack(SqStack * ps){
   ps->top = -1;
}

int StackEmpty(SqStack * ps){
   return ps->top == -1;
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

int getTop(SqStack *ps, ElemType * x){
   if(ps->top == -1){
       return 0;
   }
   *x = ps->data[ps->top];
   return 1;
}


int isSymmetry(LinkList *pL){
   SqStack stack;
   InitStack(&stack);
   Node * one = pL;
   Node * two = pL;
   char c = 0;
   while(two->next){
       one = one->next;
       two = two->next;
       if(two->next){
           Push(&stack, one->data);
           two = two->next;
       }
   }
   if(one->next == NULL){
       return 1;
   }
   one = one->next;
   while(one){
       Pop(&stack, &c);
       if(one->data != c){
           return 0;
       }
       one = one->next;
   }
   return 1;
}

void test1(){
   char * str = "xyyx";
   LinkList * list = genLinkList(str);
   printf("input:");
   display(list);
   printf("output:%d\n",isSymmetry(list));
   release(list);
}

int main(){
   test1();
   return 0;
}
