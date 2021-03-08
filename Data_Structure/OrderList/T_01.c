//
//  T_01.c
//  Data_Structure
//
//  Created by CC on 2021/3/1.
//  Copyright © 2021 CC. All rights reserved.
//

/*
 
 从顺序表中删除具有最小值的元素（假设唯一）并由函数返回被删元素的值。
 空出的位置由最后一个元素填补，若顺序表为空则显示出错信息并退出运行。
 
 教训：本题也可用函数返回值返回，两者的区别是：函数返回值只能返回一个值，而参数返回（引用传参）可以返回多个值。
      so,函数返回可以代表程序的正常运行，参数返回才是题中所要求
 
 */

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50

typedef struct{
    int data[MaxSize];
    int length;
}SqList;

//********************************************************//

int delMin(SqList * list){
    if(list->length == 0){
        printf("err! length = 0");
        exit(0);
    }
    int minIndex = 0;
    int min = list->data[minIndex];
    int i = 0;
    for(i = 1; i < list->length; i++){
        if(list->data[i] < min){
            minIndex = i;
            min = list->data[i];
        }
    }
    list->data[minIndex] = list->data[list->length -1];
    list->length --;
    return min;
}

// 改为
int delMin1(SqList * list,int * e){
    if(list->length == 0){
        return 0;
    }
    int minIndex = 0;
    int min = list->data[minIndex];
    int i = 0;
    for(i = 1; i < list->length; i++){
        if(list->data[i] < min){
            minIndex = i;
            min = list->data[i];
        }
    }
    list->data[minIndex] = list->data[list->length -1];
    list->length --;
    *e = min;
    return 1;
}

//********************************************************//

void listInit(SqList * list,int arr[], int sz){
    int i = 0;
    for(i = 0; i < sz; i++){
        list->data[i] = arr[i];
    }
    list->length = sz;
}

void print(const SqList * list){
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

void test0(int * arr, int sz){
    int min;
    SqList list;
    listInit(&list, arr, sz);
    print(&list);
    printf("\n");
    min = delMin(&list);
    printf("del min : %d\n", min);
    print(&list);
    printf("\n");
}

void test0_1(int * arr, int sz){
    int min;
    SqList list;
    listInit(&list, arr, sz);
    print(&list);
    printf("\n");
    if(delMin1(&list,&min)){
        printf("del min : %d\n", min);
    }else{
        printf("err! length = 0");
    }
    print(&list);
    printf("\n");
}

void test1(){
    int arr[] = {4,3,2,1,5,6,7,8,9,0};
    int sz = sizeof(arr)/sizeof(arr[0]);
    test0(arr,sz);
}

void test1_1(){
    int arr[] = {4,3,2,1,5,6,7,8,9,0};
    int sz = sizeof(arr)/sizeof(arr[0]);
    test0_1(arr,sz);
}

void test2(){
    int arr[] = {4,3,2,1,0,5,6,7,8,9};
    int sz = sizeof(arr)/sizeof(arr[0]);
    test0(arr,sz);
}



int main(){
    test1();
    test2();
    test1_1();
    return 0;
}

