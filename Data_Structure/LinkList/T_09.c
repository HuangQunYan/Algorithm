//
//  T_09.c
//  Data_Structure
//
//  Created by CC on 2021/3/2.
//  Copyright © 2021 CC. All rights reserved.
//

/**
 给定一个带表头结点的单链表，设head为头指针，结点结构为(data,next),data为整型元素，next为指针，
 试写出算法：按递增次序输出单链表中各结点的数据元素，并释放结点所占的存储空间
 （要求：不允许使用数组作为辅助空间）。
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
   int data;
   struct Node * next;
}Node,LinkList;


void  increaseOutput(LinkList * list){
   while(list->next){//第一个数据结点存在
       Node * min = list->next;
       Node * minPrev = list;
       Node * currPrev = list->next;//第一个数据结点
       Node * curr = currPrev->next;//第二个数据结点
       while(curr){
           if(curr->data < min->data){
               minPrev = currPrev;
               min = curr;
           }
           currPrev = curr;
           curr = currPrev->next;
       }
       printf(" %d -> ", min->data);
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
   printf("list:\n");
   LinkList * list = listInsert();
   printf("input:\nlist:");
   display(list->next);
   printf("\noutput:\nlist:");
   increaseOutput(list);
   printf("\n");
   release(list);
}

int main(){
   test1();
   return 0;
}


