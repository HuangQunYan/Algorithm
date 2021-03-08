//
//  T_05.c
//  Data_Structure
//
//  Created by CC on 2021/3/2.
//  Copyright © 2021 CC. All rights reserved.
//

//试编写算法将带头结点的单链表就地逆置，所谓“就地”是指辅助空间复杂度为O(1)

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
   int data;
   struct Node * next;
}Node,LinkList;


void reverse(LinkList * list){
   Node * p = list->next; //第一个数据结点的地址
   Node * tmp = NULL;
   list->next = NULL;
   while(p){
       tmp = p->next;
       p->next = list->next;
       list->next = p;
       p = tmp;
   }
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
   LinkList * list = listInsert();
   printf("list:");
   display(list->next);
   printf("\n");
   reverse(list);
   printf("after:");
   display(list->next);
   printf("\n");
   release(list);
}

int main(){
   test1();
   return 0;
}



