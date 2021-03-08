//
//  T_10.c
//  Data_Structure
//
//  Created by CC on 2021/3/2.
//  Copyright © 2021 CC. All rights reserved.
//

/**
    将一个带头结点的单链表A分解为两个带头结点的单链表A和B，使得A表中含有原表中序号为奇数的元素，
    而B表中含有原表中序号为偶数的元素，且保持其相对顺序不变。
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
   int data;
   struct Node * next;
}Node,LinkList;


void  split(LinkList * A,LinkList * B){
   Node * odd = A->next;//第一个数据，奇数
   Node * even = NULL;
   Node * tail = B;
   while(odd && (even = odd->next)){
       odd->next = even->next;
       even->next = NULL;
       tail->next = even;
       tail = even;
       odd = odd->next;
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
   printf("A:\n");
   LinkList * A = listInsert();
   printf("B:\n"); //B仅有头结点
   LinkList * B = (LinkList *)malloc(sizeof(Node));
   B->next = NULL;
   printf("input:\nA:");
   display(A->next);
   printf("\ninput:\nB:");
   display(B->next);
   split(A,B);
   printf("\noutput:\nA:");
   display(A->next);
   printf("\noutput:\nB:");
   display(B->next);
   printf("\n");
   release(A);
   release(B);
}

int main(){
   test1();
   return 0;
}
