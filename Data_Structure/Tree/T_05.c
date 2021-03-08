//
//  T_05.c
//  Data_Structure
//
//  Created by CC on 2021/3/6.
//  Copyright © 2021 CC. All rights reserved.
//

// 已知一棵二叉树按顺序存储结构进行存储，设计一个算法，求编号分别为i和j的两个结点
// 的最近的公共祖先结点的值

#include <stdio.h>

#define MaxSize 15

typedef  struct{
   int data[MaxSize];
}Tree;

int findAncestor(Tree * t, int i , int j){
   while(i != j){
       if(i > j){
           i = i/2;
       }else{
           j = j/2;
       }
   }
   return t->data[i-1];
}

Tree tree ;
void initTree(){
   int i = 0;
   for(i = 1; i <= MaxSize ; i++){
       tree.data[i -1] = i;
   }
}

void test0(int index1,int index2 ){
   int result = findAncestor(&tree, index1,index2);
   printf("%d\n",result);
}

void test1(){
   test0(14,15);
}

void test2(){
   test0(12,15);
}

void test3(){
   test0(5,15);
}

int main(){
   initTree();
   test1();
   test2();
   test3();
   return 0;
}
