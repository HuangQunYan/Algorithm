//
//  T_14.c
//  Data_Structure
//
//  Created by CC on 2021/3/2.
//  Copyright © 2021 CC. All rights reserved.
//

/**
设A和B是两个单链表（带头结点）,其中元素递增有序。设计一个算法从A到B中的公共元素产生单链表C，要求不破坏A、B的结点
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
   int data;
   struct Node * next;
}Node,LinkList;

int PARAM_ERROR = 1;

//假设其单链表是带有头结点的
static void  genCommonEle(LinkList * A,LinkList * B,LinkList * C){
   Node * node = NULL;
   Node * Atail = A;
   B = B->next;
   C = C->next;
   while(B && C){
       if(B->data < C->data){
           B = B->next;
           continue;
       }
       if(B->data > C->data){
           C = C->next;
           continue;
       }
       //B->data == C->data
       if((!node) || (node && node->data != B->data)){
           node  = (Node *)malloc(sizeof(Node));
           node->data = B->data;
           node->next = NULL;
           Atail->next = node;
           Atail = node;
       }
       B = B->next;
       C = C->next;
   }
}

static LinkList *  listInsert(){
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

static void release(LinkList * list){
   Node * p;
   while(list){
       p = list->next;
       free(list);
       list = p;
   }
}

static void display(const LinkList * list){
   Node *p = (Node *)list;
   while(p){
       printf(" %d ->", p->data);
       p = p->next;
   }
}

static void test1(){
   printf("B:\n");
   LinkList * B = listInsert();
   printf("C:\n");
   LinkList * C = listInsert();
   LinkList * A = (LinkList *)malloc(sizeof(Node));
   A->next= NULL;

   printf("\ninput:\nB:");
   display(B->next);
   printf("\nC:");
   display(C->next);
   printf("\nA:");
   display(A->next);

   genCommonEle(A,B,C);

   printf("\noutput:\nB:");
   display(B->next);
   printf("\nC:");
   display(C->next);
   printf("\nA:");
   display(A->next);
   printf("\n");
   release(A);
   release(B);
   release(C);

}

int main(){
   test1();
   return 0;
}

