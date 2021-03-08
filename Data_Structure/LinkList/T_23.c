//
//  T_23.c
//  Data_Structure
//
//  Created by CC on 2021/3/3.
//  Copyright © 2021 CC. All rights reserved.
//

//用单链表保存m个整数，结点的结构为[data][link]，且|data| <= n(n作为正整数)。
//现要求设计一个时间复杂度尽可能高效的算法，对于链表中data的绝对值相等的结点，
//仅保留第一次出现的结点而删除其余绝对值相等的结点。例如，若给定的单链表head如下：
//head -> __ ->21->(-15)->(-15)->(-7)->15->
//改成 head -> __ ->21->(-15)->(-7)->

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
   int data ;
   struct Node * next;
}Node,LinkList;


//去重|data|相同的只能出前一次

void T_23(LinkList * L, int n){
   char * nums = (char *)malloc(sizeof(char)*(n+1));
   memset(nums,0,sizeof(char)*(n+1));
   
   Node * prev = L;
   Node * curr = prev->next;
   while(curr){
       int data = curr->data;
       data = (data >= 0) ? data:-data;
       if(nums[data] == 0){
           //没存在，存入
           nums[data] = 1;
           prev = curr;
       }else{
           //已经存在,删除
           prev->next = curr->next;
           free(curr);
       }
       curr = prev->next;
   }
   free(nums);
}

   //释放L生成时用malloc开辟的空间
void release(LinkList * L){
   Node * nd = NULL;
   while(L){
       nd = L->next;
       free(L);
       L = nd;
   }
}


   //生成链表
void genLinkList(LinkList ** ppL, int * arr, int sz){
   LinkList * pheadNode = (LinkList *)malloc(sizeof(LinkList)); //头结点
   int i = 0; //遍序arr用的
   Node * nd = NULL;
   Node * tail = pheadNode; //尾巴，使用尾插法
   
   //初始化头结点
   pheadNode->next = NULL;

   for(i = 0; i < sz; i++){
       nd = (Node *)malloc(sizeof(Node));
       nd->data = arr[i];
       nd->next = NULL;
       
       tail->next = nd;
       tail = nd;
   }
   
   *ppL = pheadNode; //生成返回链表
}

   //展示链表的内容
void display(LinkList * L){
   Node * dn = L->next; //数据结点
   while(dn){
       printf(" %d ->",dn->data);
       dn = dn->next;
   }
   printf("\n");
}

void test1(){
   int arr[] ={21,-15,-15,-7,15};
   int m = sizeof(arr)/sizeof(arr[0]);
   int n = 22;
   LinkList * pL = NULL;
   genLinkList(&pL, arr, m);
   printf("before:\n");
   display(pL);
   
   T_23(pL,n);
   
   printf("after:\n");
   display(pL);
   release(pL);
}

int main(){
   test1();
   return 0;
}
