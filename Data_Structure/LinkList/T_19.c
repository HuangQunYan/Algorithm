//
//  T_19.c
//  Data_Structure
//
//  Created by CC on 2021/3/2.
//  Copyright © 2021 CC. All rights reserved.
//

/**
设有一个带头结点的循环单链表，其结点值均为正整数。
设计一个算法，反复找出单链表中结点值最小的结点并输出，然后将该结点从中删除，直到单链表空为止，再删除表头结点。
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
   int data;
   struct Node * next;
}Node, LinkList;


static void del_output(LinkList * list){
   while(list->next != list){//有数据
       Node * min_prev = list;
       Node * min = min_prev->next;
       Node * curr_prev = list;
       Node * curr = curr_prev->next;
       while(curr != list){
           if(curr->data < min->data){
               min = curr;
               min_prev = curr_prev;
           }
           curr_prev = curr;
           curr = curr_prev->next;
       }
       //删除最小
       min_prev->next = min->next;
       printf(" %d ->",min->data);
       free(min);
   }
   free(list);
}

//生成循环链表
static void genCLinkList(LinkList ** plist,int arr[],int sz){
   LinkList * list = (LinkList *)malloc(sizeof(LinkList)); //头结点
   Node * tail = list;
   int i = 0;
   list->next = list;
   for(i= 0; i < sz; i++){
       Node * nd = (Node *)malloc(sizeof(Node));
       nd -> data = arr[i];
       nd->next = list;
       tail->next = nd;
       tail = nd;
   }
   *plist = list;
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
   int arr[] = {1,2,5,3,1,4};
   int sz = sizeof(arr)/sizeof(arr[0]);
   LinkList * list = NULL;
   genCLinkList(&list, arr,sz);
   
   printf("input:\nlist:");
   display(list);
   printf("\n");

   del_output(list);
   printf("\n");
}

int main(){
   test1();
   return 0;
}
