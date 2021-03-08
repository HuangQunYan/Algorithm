//
//  T_25.c
//  Data_Structure
//
//  Created by CC on 2021/3/3.
//  Copyright © 2021 CC. All rights reserved.
//

//设线性表L=(a1,a2,a3,...,an-2,an-1,an)采用带头结点的单链表保存，链表中的结点定义如下：
//typedef struct node{
//    int data;
//    struct node * next;
//}NODE;
//请设计一个空间复杂度为O(1)且时间上尽可能高效的算法，重新排列L中的各结点，得到线性表L‘=（a1,a2,a3,...,an-2,an-1,an);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
   int data;
   struct node * next;
}NODE;

typedef NODE Node;
typedef NODE LinkList;



//去重|data|相同的只能出前一次

void T_25(LinkList * L){
   Node * p = L; //每次往前一步
   Node * q = L; //每次往前二步
   while(q->next){
       p = p->next;
       q = q->next;
       if(q->next){
           q = q->next;
       }
   }
   //从p后这里断开；
   if(p->next == NULL){
       return;
   }
   q = p->next;
   p->next = NULL;
   //把q开头的当成一个新的list,头插法
   Node * L2 = q; //没有头结点
   q = q->next;
   L2->next = NULL;
   while(q){
       //把q摘出来
       p = q->next;
       q->next = NULL;
       q->next = L2;
       L2 = q;
       q = p;
   }
   //合并
   p = L->next;
   q = L2;
   while(q){
       L2 = L2->next;
       q->next = NULL;
       q->next = p->next;
       p->next = q;
       p = q->next;
       q = L2;
   }
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
   int arr[] ={1,2,3,4,5,6};
   int sz = sizeof(arr)/sizeof(arr[0]);
   LinkList * pL = NULL;
   genLinkList(&pL, arr, sz);
   printf("before:\n");
   display(pL);
   
   T_25(pL);
   
   printf("after:\n");
   display(pL);
   release(pL);
}

int main(){
   test1();
   return 0;
}
