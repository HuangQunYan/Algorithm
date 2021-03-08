//
//  T_13.c
//  Data_Structure
//
//  Created by CC on 2021/3/1.
//  Copyright © 2021 CC. All rights reserved.
//

//给定一个含n(n>=1)个整数的数组，请设计一个在时间上尽可能高效的算法，找出数组中未出现的最小正整数。
//例如，数组{-5,3,2,3}中未出现的最小正整数是1,数组{1,2,3}中未出现的最小正整数是4.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int find(int * arr,int sz){
    char * ch = malloc(sizeof(char)* sz);
    memset(ch,0,sizeof(char)* sz);
    int i = 0;
    for(i = 0; i < sz; i++){
        if(arr[i] >= 1 && arr[i] <= sz){
            ch[arr[i] -1] = 1;
        }
    }
    for(i = 0; i < sz; i++){
        if(ch[i] != 1){
            break;
        }
    }
    free(ch);
    return i + 1;

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

static void test0(int A[],int sz){
    printf("input:");
    display(A,sz);
    printf("\noutput: %d \n",find(A,sz));
}
static void test1(){
    int A[] = {-5,3,2,3};
    int sz = sizeof(A)/sizeof(A[0]);
    test0(A,sz);
}

static void test2(){
    int A[] = {1,2,3};
    int sz = sizeof(A)/sizeof(A[0]);
    test0(A,sz);
}

int main(){
    test1();
    test2();
    return 0;
}
