//
//  T_06.c
//  Data_Structure
//
//  Created by CC on 2021/3/2.
//  Copyright © 2021 CC. All rights reserved.
//

//有一个带头结点的单链表L，设计一个算法使其元素递增有序。

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
   int data;
   struct Node * next;
}Node,LinkList;


void sort(LinkList * list){
   if(list->next == NULL){//第一个数据结点为空
       return;
   }
   Node * prev = list->next; //第一个数据结点，代表当前处理的数据的前继
   Node * curr = prev->next; //第二个数据结点,代表当前处理的数据
   while(curr){
       if(curr->data < prev->data){//要处理
           //把curr摘出来
           prev->next = curr->next;
           curr->next = NULL;
           //查找合适的位置放下去
           Node * tmp_prev = list;
           Node * tmp = list->next;
           while(curr->data > tmp->data){ //找到tmp是第一个比curr大的数据
               tmp_prev = tmp;
               tmp = tmp->next;
           }
           tmp_prev->next = curr;
           curr->next = tmp;
           //修正curr，让其继续往下进行
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
   printf("list:");
   display(list->next);
   printf("\n");
   sort(list);
   printf("after:");
   display(list->next);
   printf("\n");
   release(list);
}

int main(){
   test1();
   return 0;
}
