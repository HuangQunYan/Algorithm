//
//  T_04.c
//  Data_Structure
//
//  Created by CC on 2021/3/2.
//  Copyright © 2021 CC. All rights reserved.
//

//试编写在带头结点的单链表L中删除一个最小值结点的高效算法（假定最小值是唯一的）

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
   int data;
   struct Node * next;
}Node,LinkList;

void delMin(LinkList *  list){
   Node * prev = list;
   Node * minPrev = prev;
   while(prev->next){//找出最小
       if(prev->next->data < minPrev->next->data){
           minPrev = prev;
       }
       prev = prev->next;
   }
   if(minPrev->next){
       printf("the min = %d\n",minPrev->next-> data);
       Node * min = minPrev->next;
       minPrev->next = min->next;
       free(min);
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
   delMin(list);
   printf("after:");
   display(list->next);
   printf("\n");
   release(list);
}

int main(){
   test1();
   return 0;
}
