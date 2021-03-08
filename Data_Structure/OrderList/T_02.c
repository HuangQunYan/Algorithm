//
//  T_02.c
//  Data_Structure
//
//  Created by CC on 2021/3/1.
//  Copyright © 2021 CC. All rights reserved.
//

/*
 
 设计一个高效算法，将顺序表L的所有元素逆置，要求算法的空间复杂度为O(1)
 
 */

#include <stdio.h>

#define MaxSize 50

typedef struct {
    int data[MaxSize];
    int length;
}SqList;

void reverse(SqList * list){
    int left = 0;
    int right = list->length -1;
    int tmp = 0;
    while(left < right){
        tmp = list->data[left];
        list->data[left] = list->data[right];
        list->data[right] = tmp;
        left++;
        right--;
    }
}

void listInit(SqList * list, int * arr, int sz){
    int i = 0;
    for(i = 0; i < sz; i++){
        list->data[i] = arr[i];
    }
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

void test1(){
    int arr[] = {0,1,2,3,4,5,6,7,8,9};
    int sz = sizeof(arr)/sizeof(arr[0]);
    SqList list;
    listInit(&list, arr, sz);
    display(&list);
    reverse(&list);
    display(&list);
}

void test2(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int sz = sizeof(arr)/sizeof(arr[0]);
    SqList list;
    listInit(&list, arr, sz);
    display(&list);
    reverse(&list);
    display(&list);
}



int main(){
    test1();
    test2();
    return 0;
}
