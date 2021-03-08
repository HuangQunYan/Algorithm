//
//  T_03.c
//  Data_Structure
//
//  Created by CC on 2021/3/1.
//  Copyright © 2021 CC. All rights reserved.
//

/**
 
 对长度为n的顺序表L，编写一个时间复杂度为O(n)，空间复杂度为O(1)算法，该算法删除线性表中所有值为x的数据元素.
 
 */

#include <stdio.h>

typedef struct{
    int * data;
    int length;
}SqList;

void delx(SqList * list,int x){
    int i = 0;
    int j = 0;
    for(i = 0; i < list->length; i++){
        if(list->data[i] != x){
            list->data[j++] = list->data[i];
        }
    }
    // i = list->length;
    // j = 理应填充的下标
    list->length = j;
}

void listInit(SqList * list, int arr[], int sz){
    list->data = arr;
    list->length = sz;
}

void display(const SqList * list){
    int i = 0;
    printf("[");
    if(list->length > 0){
        printf(" %d ", list->data[0]);
    }
    for(i = 1; i < list->length; i++){
        printf(", %d ", list->data[i]);
    }
    printf("]\n");
}

void test0(int * arr,int sz, int x){
    SqList list;
    listInit(&list, arr, sz);
    printf("********************************\n");
    display(&list);
    delx(&list,x);
    printf("del x = %d\n", x);
    display(&list);
}

void test1(){
    int arr[] = {3,0,0,4,1,2,3,5,3,3,4,5,6,6};
    int sz = sizeof(arr)/sizeof(arr[0]);
    int delx = 1;
    test0(arr,sz,delx);
}

void test2(){
    int arr[] = {3,0,0,4,1,2,3,5,3,3,4,5,6,6};
    int sz = sizeof(arr)/sizeof(arr[0]);
    int delx = 3;
    test0(arr,sz,delx);
}


int main(){
    test1();
    test2();
    return 0;
}
