//
//  T_11.c
//  Data_Structure
//
//  Created by CC on 2021/3/2.
//  Copyright © 2021 CC. All rights reserved.
//

/**
 设C={a1,b1,a2,b2,....,an,bn}为线性表，采用头结点的hc单链表存放，
 设计一个就地算法，将其拆分为两个线性表，使得A={a1,a2,...,an},B={b1,b2,...,bn}.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
   int data;
   struct Node * next;
}Node,LinkList;

int PARAM_ERROR = 1;

int  split(LinkList * C,LinkList * A,LinkList * B){
   Node * odd = C->next;//第一个数据，奇数
   Node * even = NULL;
   Node * Atail = A;
   Node * Btail = B;
   while(odd){
       even = odd->next;
       if(even == NULL){
           return PARAM_ERROR;
       }
       C->next = even->next;
       
       odd->next = NULL;
       Atail->next = odd;
       Atail = odd;
       
       even->next = NULL;
       Btail->next = even;
       Btail = even;
       
       odd = C->next;
   }
   return 0;
}


LinkList *  listInsert(){
   LinkList * list = (LinkList *)malloc(sizeof(Node));
   Node * prev = list;
   Node * curr = NULL;
   int x = 0;
   list->next = NULL;
   printf("输入999,退出。请输入:>");
   scanf("%d",&x);
   while(x != 999){
       curr = (Node *)malloc(sizeof(Node));
       curr->data = x;
       curr->next = NULL;
       prev->next = curr;
       prev = curr;
       printf("请输入:>");
       scanf("%d",&x);
   }
   return list;
}

void release(LinkList * list){
   Node * p;
   while(list){
       p = list->next;
       free(list);
       list = p;
   }
}

void display(const LinkList * list){
   Node *p = (Node *)list;
   while(p){
       printf(" %d ->", p->data);
       p = p->next;
   }
}

void test1(){
   printf("C:\n");
   LinkList * C = listInsert();
   LinkList * A = (LinkList *)malloc(sizeof(Node));
   A->next = NULL;
   LinkList * B = (LinkList *)malloc(sizeof(Node));
   B->next = NULL;
   printf("input:\nC:");
   display(C->next);
   printf("\nA:");
   display(A->next);
   printf("\nB:");
   display(B->next);
   //
   if(split(C,A,B) == PARAM_ERROR){
       printf("参数有误");
   }
   printf("\noutput:\nC:");
   display(C->next);
   printf("\nA:");
   display(A->next);
   printf("\nB:");
   display(B->next);
   printf("\n");
   
   release(A);
   release(B);
   release(C);
}

int main(){
   test1();
   return 0;
}

