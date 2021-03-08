//
//  T_18.c
//  Data_Structure
//
//  Created by CC on 2021/3/2.
//  Copyright © 2021 CC. All rights reserved.
//

/**
 有两个循环单链表，链表头指针分别是h1和h2,编写一个函数将链表h2链接到链表h1之后，要求链接后的链表仍保持循环链表形式。
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
   int data;
   struct Node * next;
}Node, LinkList;


static LinkList * attch(LinkList * h1, LinkList * h2){
   Node * h1_tail = h1->next;
   Node * h2_tail = h2->next;
   if(h1_tail == h1){
       free(h1);
       return h2;
   }
   if(h2_tail == h2){
       free(h2);
       return h1;
   }
   while(h1_tail->next != h1){
       h1_tail = h1_tail->next;
   }
   while(h2_tail->next != h2){
       h2_tail = h2_tail->next;
   }
   h1_tail->next = h2->next;
   h2_tail->next = h1;
   free(h2);
   return h1;
}

//生成循环链表
static void genCLinkList(LinkList ** plist,int arr[],int sz){
   LinkList * list = (LinkList *)malloc(sizeof(LinkList)); //头结点
   int i = 0;
   list->next = list;
   *plist = list;
   Node * tail = list;
   for(i= 0; i < sz; i++){
       Node * nd = (Node *)malloc(sizeof(Node));
       nd -> data = arr[i];
       nd->next = list;
       tail->next = nd;
       tail = nd;
   }
}

static void release(LinkList * list){
   Node * p = list->next;
   Node * q = NULL;
   while(p != list){
       q = p->next;
       free(p);
       p = q;
   }
   free(list);
}

static void display(LinkList* list){
   Node * p = list->next;
   while(p != list){
       printf(" %d ->", p->data);
       p = p->next;
   }
}

void test1(){
   int arr1[] = {3,4,5,6};
   int sz1 = sizeof(arr1)/sizeof(arr1[0]);
   LinkList * h1 = NULL;
   genCLinkList(&h1, arr1,sz1);
   
   int arr2[] = {7,8,9,10};
   int sz2 = sizeof(arr2)/sizeof(arr2[0]);
   LinkList * h2 = NULL;
   genCLinkList(&h2, arr2,sz2);
   
   printf("input:\nh1:");
   display(h1);
   printf("\nh2:");
   display(h2);
   printf("\n");

   h1 = attch(h1,h2);
   
   printf("output:\nh1:");
   display(h1);
   printf("\n");
   
   release(h1);
}

int main(){
   test1();
   return 0;
}
