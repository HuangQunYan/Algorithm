//
//  T_12.c
//  Data_Structure
//
//  Created by CC on 2021/3/1.
//  Copyright © 2021 CC. All rights reserved.
//

//已知一个整数序列A=（a0,a1,...,an-1),其中0 <= a < n( 0 =< i < n-1)。
//若存在ap1 = ap2 = ...=apm = x 且 m > n/2 (0 <= pk < n, 1 <=k <= m),
//则称x为A的主元素。
//例如 A=（0,5,5,3,5,7,5,5），则5为主元素；
//又如 A=（0,5,5,3,5,1,5,7），则A中没有主元素。
//假设A中的n个元素保存在一个一维数组中，请设计一个尽可能高效的算法，找出A的主元素。
//若存在主元素，则输出该元素；否则输出-1.

#include <stdio.h>

static int findMainElem(int arr[],int size){
    int ele = -1;
    int count = 0;
    int i = 0;
    if(size == 0){
        return ele;
    }
    for(i = 0; i < size; i++){
        if(count == 0){
            ele = arr[i];
            count = 1;
            continue;
        }
        //count != 0;
        if(arr[i] == ele){
            count++;
        }else{
            count--;
        }
    }
    if(count > 0){
        count = 0;
        for(i = 0; i < size; i++){
            if(arr[i] == ele){
                count++;
            }
        }
        if(count > size/2){
            return ele;
        }
    }
    return -1;
}


static void display(const int * arr,int sz){
    int i = 0;
    printf("[");
    if(sz > 0){
        printf(" %d ", arr[0]);
    }
    for(i = 1; i < sz; i++){
        printf(", %d ", arr[i]);
    }
    printf("]");
}

static void test0(int arr[],int sz){
    printf("input:\n");
    display(arr, sz);
    printf("\noutput:%d\n",findMainElem(arr, sz));
}

static void test1(){
    int arr[] = {0,5,5,3,5,7,5,5};
    int sz = sizeof(arr)/sizeof(arr[0]);
    test0(arr,sz);
}


static void test2(){
    int arr[] = {0,5,5,3,5,1,5,7};
    int sz = sizeof(arr)/sizeof(arr[0]);
    test0(arr,sz);
}

int main(){
    test1();
    test2();
}
