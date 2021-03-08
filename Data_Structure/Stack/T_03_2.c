//
//  T_03_2.c
//  Data_Structure
//
//  Created by CC on 2021/3/3.
//  Copyright © 2021 CC. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

//头插法,有头结点
typedef struct Node{
   ElemType data;
   struct Node * next;
}Node,LStack; //链栈

void release(LStack * ps){
   Node * nd = NULL;
   while(ps){
       nd = ps->next;
       free(ps);
       ps = nd;
   }
}

LStack * genLStack(){
   LStack * s = (LStack *)malloc(sizeof(LStack));
   s->next = NULL;
   return s;
}

void InitLStack(LStack * ps){
   release(ps->next);
   ps->next = NULL;
}

int StackEmpty(LStack * ps){
   return (ps->next == NULL)? 1: 0;
}

int Push(LStack * ps , ElemType x){
   Node * newN = (Node *)malloc(sizeof(Node));
   newN->data =  x;
   newN-> next = ps->next;
   ps->next = newN;
   return 1;
}

int Pop(LStack *ps, ElemType * x){
   if(ps->next == NULL){
       return 0;
   }
   Node * nd = ps->next;
   ps->next = nd->next;
   *x = nd->data;
   free(nd);
   return 1;
}

int getTop(LStack *ps, ElemType * x){
   if(ps->next == NULL){
       return 0;
   }
   *x = ps->next->data;
   return 1;
}



int  isValid(char * str){
   LStack * ps = genLStack();
   int i = 0;
   int x = 0;
   for(i = 0; str[i] != '\0'; i++){
       if(str[i] == 'I'){
           Push(ps,1);
           continue;
       }
       if(!Pop(ps, &x)){
           return 0;
       }
   }
   return StackEmpty(ps);
}

void test0(char * str){
   int result = isValid(str);
   printf("%s:%s\n", str,result ? "valid": "not valid");
}

void test1(){
   char * str = "IOIIOIOO";
   test0(str);
}

void test2(){
   char * str = "IOOIOIIO";
   test0(str);
}

void test3(){
   char * str = "IIIOIOIO";
   test0(str);
}

void test4(){
   char * str = "IIIOOIOO";
   test0(str);
}

int main(){
   test1();
   test2();
   test3();
   test4();
   return 0;
}
