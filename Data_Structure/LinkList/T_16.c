//
//  T_16.c
//  Data_Structure
//
//  Created by CC on 2021/3/2.
//  Copyright © 2021 CC. All rights reserved.
//

//两个整数序列 A=a1,a2,...,am 和 B=b1,b2,...,bn已存入两个单链表中，设计一个算法，判断序列B是否是序列A的连续子序列
//后期可考虑用KMP优化

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
   int data;
   struct Node * next;
}Node,LinkList;

//假设其单链表是带有头结点的 B属于A？
int  isBelong(LinkList * A,LinkList * B){
   A = A->next;
   B = B->next;
   while(A){
       Node * a = A;
       Node * b = B;
       while(a&&b&&a->data == b->data){
           a = a->next;
           b = b->next;
       }
       if(b == NULL){
           return 1;
       }
       if(a == NULL){
           return 0;
       }
       A = A->next;
   }
   return 0;
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

static void display(const LinkList * list){
   Node *p = (Node *)list;
   while(p){
       printf(" %d ->", p->data);
       p = p->next;
   }
}

static void release(LinkList * list){
   Node * p;
   while(list){
       p = list->next;
       free(list);
       list = p;
   }
}

static void test1(){
   printf("A:\n");
   LinkList * A = listInsert();
   printf("B:\n");
   LinkList * B = listInsert();

   printf("\ninput:\nA:");
   display(A->next);
   printf("\nB:");
   display(B->next);

   printf("\nB是A的子序列？ %s\n", isBelong(A,B) ? "Yes":"NO");
   release(A);
   release(B);
}

int main(){
   test1();
   return 0;
}
