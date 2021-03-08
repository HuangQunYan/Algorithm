//
//  T_07.c
//  Data_Structure
//
//  Created by CC on 2021/3/2.
//  Copyright © 2021 CC. All rights reserved.
//

//设在一个带表头结点的单链表中所有元素结点的数据值无序，
//试编写一个函数，删除表中所有介于给定的两个值(作为函数参数给出)之间的元素的元素（若存在）。

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
   int data;
   struct Node * next;
}Node,LinkList;


void DelRange(LinkList * list,int min,int max){
   Node * prev = list; //头结点，代表当前处理的数据的前继
   Node * curr = prev->next; //第一个数据结点,代表当前处理的数据
   while(curr){
       if(curr->data > min && curr->data < max){//要处理
           //把curr摘出来
           prev->next = curr->next;
           curr->next = NULL;
           free(curr);
           curr = prev->next;
       }else{
           prev = curr;
           curr = curr->next;
       }
   }//while
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
   int min = 0,max = 0;
   printf("list:");
   display(list->next);
   printf("\n请输入要删除的最小最大值:>");
   scanf("%d%d",&min,&max);
   DelRange(list,min,max);
   printf("after:");
   display(list->next);
   printf("\n");
   release(list);
}

int main(){
   test1();
   return 0;
}

