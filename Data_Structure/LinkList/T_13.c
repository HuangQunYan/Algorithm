//
//  T_13.c
//  Data_Structure
//
//  Created by CC on 2021/3/2.
//  Copyright © 2021 CC. All rights reserved.
//

/**
 假设有两个按元素值递增次序的线性表,均以单链表形式存储。
 请编写算法将这两个单链表归并为一个按元素值递减次序排列的单链表，并要求利用原来两个单链表的结点存放归并后的单链表。
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
   int data;
   struct Node * next;
}Node,LinkList;

int PARAM_ERROR = 1;

//假设其单链表是带有头结点的
void  merge(LinkList * A,LinkList * B,LinkList * C){
   Node * node = NULL;
   Node * list = NULL;
   while(B->next && C->next){
       list = (B->next->data <= C->next->data)? B:C;
       node = list->next;
       list->next = node->next;
       node->next = A->next;
       A->next = node;
   }
   list = (B->next) ? B:C;
   while(list->next){
       node = list->next;
       list->next = node->next;
       node->next = A->next;
       A->next = node;
   }
}

static void  headInsert(LinkList * A,Node * node){
   node->next = A->next;
   A->next = node;
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

   merge(A,B,C);

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

