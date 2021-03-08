//
//  T_22.c
//  Data_Structure
//
//  Created by CC on 2021/3/2.
//  Copyright © 2021 CC. All rights reserved.
//

/**
假定采用带头结点的单链表保存单词，当两个单词有相同的后缀时，可共享相同的后缀存储空间，
例如，“loading”和"being"共享相同后缀ing。
设str1和str2分别指向两个单词所在单链表的头结点，链表结点结构为data,next,
请设计一个时间上尽可能高效的算法，找出由str1和str2所指向两个链表共同后缀的起始位置(如上文中字符串“i”的结点位置p)。
    
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
   char data;
   struct Node * next;
}Node,LinkList;

static Node * getComSuffix(LinkList * str1,LinkList * str2){
   int len1 = 0; //str1的字母长度
   int len2 = 0; //str2的字母长度
   str1 = str1->next; //第一个数据结点
   Node * p = str1;
   //计算str1的字母长度
   while(p){
       len1++;
       p = p->next;
   }
   //计算str2的字母长度
   str2 = str2->next;//第一个数据结点
   p = str2;
   while(p){
       len2++;
       p = p->next;
   }
   //调整起始位置
   int k = len1 - len2;
   if(k >= 0){
       while(k > 0){
           k--;
           str1 = str1->next;
       }
   }else{
       k = -k;
       while(k > 0){
           k--;
           str2 = str2->next;
       }
   }
   while(str1){
       if(str1 == str2){
           return str1;
       }
       str1 = str1->next;
       str2 = str2->next;
   }
   return NULL;
}

static void display(LinkList * list){
   Node * p = list->next;
   while(p){
       printf(" %c ->", p->data);
       p = p ->next;
   }
   printf("\n");
}

void test1(){
   LinkList str1;
   Node s1 = {'l',NULL};
   Node s2 = {'o',NULL};
   Node s3 = {'a',NULL};
   Node s4 = {'d',NULL};
   Node s5 = {'i',NULL};
   Node s6 = {'n',NULL};
   Node s7 = {'g',NULL};

   str1.next = &s1;
   s1.next = &s2;
   s2.next = &s3;
   s3.next = &s4;
   s4.next = &s5;
   s5.next = &s6;
   s6.next = &s7;

   LinkList str2;
   Node ss1 = {'b',NULL};
   Node ss2 = {'e',NULL};
   str2.next = &ss1;
   ss1.next = &ss2;
   ss2.next = &s5;

   printf("str1:");
   display(&str1);
   printf("str2:");
   display(&str2);

   Node* result = getComSuffix(&str1,&str2);

   if(result){
       printf("common suffix from %c ", result->data);
   }else{
       printf("no common suffix");
   }

}

int main(){
   test1();
   return 0;
}
