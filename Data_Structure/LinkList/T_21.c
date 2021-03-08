//
//  T_21.c
//  Data_Structure
//
//  Created by CC on 2021/3/2.
//  Copyright © 2021 CC. All rights reserved.
//

/**
 
 已知一个带有表头结点的单链表，结点结构为data,link
 假设该链表只给出了头指针list,在不改变链表的前提下，
 请设计一个尽可能高效的算法，查找链表中倒数第K个位置上的结点（K为正整数）。
 若查找成功，算法输出该结点的data值，并返回1;否则，只返回0。
 
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
   int data;
   struct Node * next;
}Node, LinkList;


static int findBackward(int * val,LinkList * list,int k){
   Node * prev = list->next;//第一个数据
   Node * curr = list->next;
   while(k > 0 && prev){
       prev = prev->next;
       k--;
   }
   if(k > 0){
       return 0;
   }
   while(prev){
       prev = prev->next;
       curr = curr->next;
   }
   *val = curr->data;
   return 1;
}

   //生成带有头结点的单链表
static void genLinkList(LinkList ** plist,int arr[],int sz){
   LinkList * list = (LinkList *)malloc(sizeof(LinkList)); //头结点
   Node * tail = list;
   int i = 0;
   list->next = NULL;
   for(i= 0; i < sz; i++){
       Node * nd = (Node *)malloc(sizeof(Node));
       nd -> data = arr[i];
       nd->next = NULL;
       tail->next = nd;
       tail = nd;
   }
   *plist = list;
}

static void release(LinkList * list){
   Node * tmp = NULL;
   while(list){
       tmp = list->next;
       free(list);
       list = tmp;
   }
}

   //带头结点
static void display(LinkList * list){
   Node * p = list->next;
   while(p != NULL){
       printf(" %d ->", p->data);
       p = p->next;
   }
}

void test1(){
   int arr[] = {1,2,3,4,5,6,7,8,9};
   int sz = sizeof(arr)/sizeof(arr[0]);
   int k = 5;//>0
   int val = 0;
   LinkList * list = NULL;
   genLinkList(&list, arr,sz);
   
   printf("input:\nlist:");
   display(list);
   printf("\nk: %d\n",k);

   if(findBackward(&val,list,k)){
       printf("the KTH reciprocal = %d\n",val);
   }else{
       printf("cann't find\n");
   }
   printf("\n");
   release(list);
}

int main(){
   test1();
   return 0;
}
