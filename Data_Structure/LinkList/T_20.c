//
//  T_20.c
//  Data_Structure
//
//  Created by CC on 2021/3/3.
//  Copyright © 2021 CC. All rights reserved.
//

/**
 设头指针为L的带表头结点的非循环双向链表，其每个结点中除有pred（前驱指针）、
 data（数据）和next（后缀指针）域外，还有一个访问频度域freq。
 在链表被启用前，其值均初始化为0.每当在链表中进行一次Locate(L,x)运算时，
 令元素值为x的结点中freq域的值增1,并使此链表结点保持按访问频度非增(递减)
 的顺序排列，同时最近访问的结点排在频度相同的结点前面，以便使频繁访问的结点总是靠近表头。
 试编写符合上述要求的Locate(L,x)运算的算法，该运算为函数过程，返回找到结点的地址，类型为指针型。
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
   int data;
   int freq;
   struct Node * pred;
   struct Node * next;
}Node,DLinkList;


Node *  Locate(DLinkList *L , int x){
   Node * dN = L->next;//数据结点
   while(dN && dN->data != x){
       dN = dN->next;
   }
   //dN 为空 或 dN为所求
   if(dN == NULL){
       return NULL;
   }
   //dN不为空
   //把dN摘除
   Node * tmp = dN->pred;
   tmp->next = dN->next;
   dN->next->pred = tmp;
   dN->freq += 1;
   //把dN插入
   while(tmp != L && tmp->freq <= dN->freq){
       tmp = tmp->pred;
   }
   dN->next = tmp->next;
   dN->pred = tmp;
   tmp->next->pred = dN;
   tmp->next = dN;
   return dN;
}


   //释放L生成时用malloc开辟的空间
void release(DLinkList * L){
   Node * nd = NULL;
   while(L){
       nd = L->next;
       free(L);
       L = nd;
   }
}


   //生成链表
void genDLinkList(DLinkList ** ppL, int * arr, int sz){
   DLinkList * pheadNode = (DLinkList *)malloc(sizeof(DLinkList)); //头结点
   int i = 0; //遍序arr用的
   Node * nd = NULL;
   Node * tail = pheadNode; //尾巴，使用尾插法

   //初始化头结点
   pheadNode->next = NULL;
   pheadNode->pred = NULL;

   for(i = 0; i < sz; i++){
       nd = (Node *)malloc(sizeof(Node));
       nd->data = arr[i];
       nd->freq = 0;

       nd->next = NULL;
       nd->pred = tail;
       tail->next = nd;
       tail = nd;
   }

   *ppL = pheadNode; //生成返回链表
}

   //展示链表的内容
void display(DLinkList * L){
   Node * dn = L->next; //数据结点
   while(dn){
       printf("{data:%d,freq:%d}->\n",dn->data,dn->freq);
       dn = dn->next;
   }
}

void test1(){
   int arr[] ={0,1,2,3,4,5,6,7,8,9};
   int sz = sizeof(arr)/sizeof(arr[0]);
   DLinkList * pL = NULL;
   genDLinkList(&pL, arr, sz);
   printf("before:\n");
   display(pL);

   Locate(pL, 2);
   Locate(pL, 2);
   Locate(pL, 3);
   Locate(pL, 4);
   Locate(pL, 4);
   Locate(pL, 4);

   printf("after:\n");
   display(pL);
   release(pL);
}

int main(){
   test1();
   return 0;
}
