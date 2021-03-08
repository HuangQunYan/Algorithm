//
//  T_05.c
//  Data_Structure
//
//  Created by CC on 2021/3/1.
//  Copyright © 2021 CC. All rights reserved.
//


// 从顺序表中删除其值在给定值s与t之间（包含s和t,要求s < t）的所有元素，如果s或t不合理或顺序表为空，则显示出错信息并退出运行.


#include <stdio.h>

typedef struct{
    int * data;
    int length;
}SqList;

int LIST_EMPTY = 1;
int PARAM_ILLEGAL = 2;

int del_s_to_t(SqList * list , int s,int t){
    if(list->length == 0){
        return LIST_EMPTY;
    }
    if(s >= t){
        return PARAM_ILLEGAL;
    }
    int i = 0;
    int j = 0;
    for(i = 0; i < list->length; i++){
        if(!(list->data[i] >= s && list->data[i] <= t)){
            //删
            list->data[j++] = list->data[i];
        }
    }
    list->length = j ;
    return 0;
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

void test0(int * arr,int sz,int s, int t){
    int result = 0;
    SqList list;
    listInit(&list, arr, sz);
    printf("************************************\n");
    printf("before:\n");
    display(&list);
    printf("\n");
    printf("s = %d, t = %d\n",s,t);
    result = del_s_to_t(&list,s,t);
    printf("after:\n");
    if(result == PARAM_ILLEGAL){
        printf("参数不合理!\n");
    }else if(result == LIST_EMPTY){
        printf("顺序表为空!\n");
    }else{
        display(&list);
        printf("\n");
    }
}


void test1(){
    int arr[] = {};
    int sz = sizeof(arr)/sizeof(arr[0]);
    test0(arr,sz,3,5);
}


void test2(){
    int arr[] = {1,2,3};
    int sz = sizeof(arr)/sizeof(arr[0]);
    test0(arr,sz,5,3);
}

void test3(){
    int arr[] = {1,2,3,4,6,7,8,8};
    int sz = sizeof(arr)/sizeof(arr[0]);
    test0(arr,sz,2,6);
}

int main(){
    test1();
    test2();
    test3();
    return 0;
}

