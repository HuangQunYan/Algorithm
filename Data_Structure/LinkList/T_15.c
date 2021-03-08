//
//  T_15.c
//  Data_Structure
//
//  Created by CC on 2021/3/2.
//  Copyright © 2021 CC. All rights reserved.
//


/**
 已知两个链表A和B分别表示两个集合，其元素递增排列。
 编制函数，求A与B的交集，并存放于A链表中
 集合内的元素并不重复，对吧？
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
   int data;
   struct Node * next;
}Node,LinkList;

static void release(LinkList * list){
   Node * p;
   while(list){
       p = list->next;
       free(list);
       list = p;
   }
}

//假设其单链表是带有头结点的
static void  genCommonEle(LinkList * A,LinkList * B){
   Node * prev = A;
   Node * curr = prev->next;
   B = B->next;
   while(curr){
       while(B && B->data < curr->data){
           B = B->next;
       }
       if(!B){
           prev->next = NULL;
           release(curr);
           break;
       }
       if(B->data == curr->data){
           //保留curr
           prev = curr;
           curr = prev->next;
           B = B->next;
       }else{ //B->data > curr->data
           //删除curr
           prev->next = curr->next;
           free(curr);
           curr = prev->next;
       }
   }//while(curr)
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

static void test1(){
   printf("A:\n");
   LinkList * A = listInsert();
   printf("B:\n");
   LinkList * B = listInsert();

   printf("\ninput:\nA:");
   display(A->next);
   printf("\nB:");
   display(B->next);

   genCommonEle(A,B);

   printf("\noutput:\nA:");
   display(A->next);
   printf("\nB:");
   display(B->next);
   printf("\n");
   release(A);
   release(B);
}

int main(){
   test1();
   return 0;
}
