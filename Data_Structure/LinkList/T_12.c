//
//  T_12.c
//  Data_Structure
//
//  Created by CC on 2021/3/2.
//  Copyright © 2021 CC. All rights reserved.
//

/**
 在一个递增有序的线性表中，有数值相同的元素存在。若存储方式为单链表，设计算法去掉
 数值相同的元素，使表中不再有重复的元素，例如(7,10,10,21,30,42,42,42,51,70)
 将变为(7,10,21,30,42,51,70)
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
   int data;
   struct Node * next;
}Node,LinkList;

int PARAM_ERROR = 1;

//假设其单链表是带有头结点的
int  removeDuplicates(LinkList * A){
   Node * prev = A->next; //第一个数据结点的地址
   if(prev == NULL){
       return 0;
   }
   Node * curr = prev->next;//第二个数据结点的地址
   while(curr){
       if(curr->data < prev->data){
           return PARAM_ERROR;
       }
       if(prev->data == curr->data){//去掉curr
           prev->next = curr->next;
           free(curr);
       }else{
           prev = curr;
       }
       curr = prev->next;
   }
   return 0;
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
   printf("A:\n");
   LinkList * A = listInsert();
   printf("input:\nA:");
   display(A->next);
   
   removeDuplicates(A);
   
   printf("\noutput:\nA:");
   display(A->next);
   printf("\n");
   release(A);
}

int main(){
   test1();
   return 0;
}
