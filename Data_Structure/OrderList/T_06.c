//
//  T_06.c
//  Data_Structure
//
//  Created by CC on 2021/3/1.
//  Copyright © 2021 CC. All rights reserved.
//

//从有序顺序表中删除所有其值重复的元素，使表中所有元素均不同。

#include <stdio.h>

typedef struct{
    int * data;
    int length;
}SqList;

void removeDuplicates(SqList * list){
    int i = 0;
    int j = 1;
    for(i = 1; i < list->length; i++){
        if(list->data[i] != list->data[i-1]){//和前一个元素重复
            list->data[j++] = list->data[i];
        }
    }
    list->length = j;
}

void listInit(SqList * list, int * arr, int sz){
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
    printf("]");
}

void test0(int * arr,int sz){
    SqList list;
    listInit(&list, arr, sz);
    printf("************************************\n");
    printf("before:\n");
    display(&list);
    printf("\n");
    removeDuplicates(&list);
    printf("after:\n");
    display(&list);
    printf("\n");
}


void test1(){
    int arr[] = {1,2,3,4,5};
    int sz = sizeof(arr)/sizeof(arr[0]);
    test0(arr,sz);
}


void test2(){
    int arr[] = {1,2,2,2,3};
    int sz = sizeof(arr)/sizeof(arr[0]);
    test0(arr,sz);
}

void test3(){
    int arr[] = {1,2,3,4,6,7,8,8};
    int sz = sizeof(arr)/sizeof(arr[0]);
    test0(arr,sz);
}

int main(){
    test1();
    test2();
    test3();
    return 0;
}

