//
//  T_17.c
//  Data_Structure
//
//  Created by CC on 2021/3/2.
//  Copyright © 2021 CC. All rights reserved.
//

/**
 设计一个算法用于判断带头结点的循环双链表是否对称
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
   int data;
   struct Node * prev;
   struct Node * next;
}DNode, DLinkList;

static int symmetry(DLinkList * list){
   DNode * first = list->next;
   DNode * last = list->prev;
   if(first == list){
       //没有数据
       return 0;
   }
   while(first != last){
       if(first->data != last->data){
           return 0;
       }
       if(first->next == last){
           return 1;
       }
       first = first->next;
       last = last->prev;
   }
   return 1;
}

//生成循环双链表
static void genCDLL(DLinkList ** plist,int arr[],int sz){
   DLinkList * list = (DLinkList *)malloc(sizeof(DLinkList));
   int i = 0;
   list->prev = list;
   list->next = list;
   *plist = list;
   DNode * p = NULL;
   for(i= 0; i < sz; i++){
       DNode * nd = (DNode *)malloc(sizeof(DNode));
       nd -> data = arr[i];
       p = list; //新的节点插在list之前
       nd->next = list;
       nd->prev = list->prev;
       nd->prev->next = nd;
       list->prev = nd;
   }
}

static void release(DLinkList * list){
   DNode * p = list->next;
   DNode * q = NULL;
   while(p != list){
       q = p->next;
       free(p);
       p = q;
   }
   free(list);
}

static void display(DLinkList* list){
   DNode * p = list->next;
   while(p != list){
       printf(" %d ->", p->data);
       p = p->next;
   }
}

void test1(){
   int arr[] = {1,2,2,1};
   int sz = sizeof(arr)/sizeof(arr[0]);
   DLinkList * list = NULL;
   genCDLL( &list, arr,sz);
   printf("input:\nlist:");
   display(list);
   printf("\n");
   
   printf("output:is symmetry ? %s\n" , symmetry(list) ? "Yes":"No");
   
   display(list);
   release(list);
}

int main(){
   test1();
   return 0;
}
