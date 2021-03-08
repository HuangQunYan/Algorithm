//
//  T_08.c
//  Data_Structure
//
//  Created by CC on 2021/3/2.
//  Copyright © 2021 CC. All rights reserved.
//

//给定两个单链表，编写算法找出两个链表的公共结点

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
   int data;
   struct Node * next;
}Node,LinkList;


Node * findCommon(LinkList * A, LinkList * B){
   int A_len = 0;
   int B_len = 0;
   int skip = 0;
   Node * p = A->next;//第一个数据结点
   while(p){
       A_len ++;
       p = p->next;
   }
   p = B->next;//第一个数据结点
   while(p){
       B_len ++;
       p = p->next;
   }
   if(A_len == 0 || B_len == 0){
       return NULL;
   }
   A = A->next; //第一个数据结点
   B = B->next; //第一个数据结点
   if(A_len >= B_len){
       skip = A_len -B_len;
       while(skip > 0){
           skip--;
           A= A->next;
       }
   }else{
       skip = -(A_len -B_len);
       while(skip > 0){
           skip--;
           B = B->next;
       }
   }
   while(A && B && A!= B){
       A = A->next;
       B = B->next;
   }
   return A;
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

void  genCommonNode(LinkList * A,LinkList * B){
   Node * first = NULL;
   Node * prev = NULL;
   Node * curr = NULL;
   int x = 0;
   printf("输入999,退出。请输入:>");
   scanf("%d",&x);
   while(x != 999){
       curr = (Node *)malloc(sizeof(Node));
       curr->data = x;
       curr->next = NULL;
       if(prev == NULL){
           first = curr;
           prev = curr;
       }else{
           prev->next = curr;
           prev = curr;
       }
       printf("请输入:>");
       scanf("%d",&x);
   }
   if(first == NULL){
       return;
   }
   prev = A;
   while(prev->next){
       prev = prev->next;
   }
   prev->next = first;
   
   prev = B;
   while(prev->next){
       prev = prev->next;
   }
   prev->next = first;
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

void release1(LinkList * A, LinkList * B,Node * com){
   Node * p;
   while(A && A != com){
       p = A->next;
       free(A);
       A = p;
   }
   
   while(B){
       p = B->next;
       free(B);
       B = p;
   }
}


void test1(){
   Node * com = NULL;
   printf("A:\n");
   LinkList * A = listInsert();
   printf("B:\n");
   LinkList * B = listInsert();
   printf("common:\n");
   genCommonNode(A,B);
   printf("input:\nA:");
   display(A->next);
   printf("\nB:");
   display(B->next);
   printf("\n");
   com = findCommon(A,B);
   if(com){
      printf("find common node: %d\n", com->data);
   }else{
       printf("can't find common node!\n");
   }
   release1(A,B,com);
}

int main(){
   test1();
   return 0;
}


