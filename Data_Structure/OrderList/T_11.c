//  
//  T_11.c
//  Data_Structure
//
//  Created by CC on 2021/3/1.
//  Copyright © 2021 CC. All rights reserved.
//

//一个长度为L(L>=1)的升序序列S，处于(L除以2向上取整)得到的位置的数称为S的中位数。例如，若序列S1=(11,13,15,17,19),
//则S1的中位数是15,两个序列的中位数是含它们所有元素的升序序列的中位数。例如，若S2=（2,4,6,8,20)，则S1和S2的中位数是11.
//现在有两个等长升序序列A和B，试设计一个在时间和空间两方面都尽可能高效的算法，找出两个序列A和B的中位数。

#include <stdio.h>

static int findMid(int * A,int * B,int sz){
    int i = 0;
    int j = 0;
    int k = 0;
    int cur = 0;
    for(i = 0,j = 0;i < sz && j < sz; ){
        if(A[i] <= B[j]){
            cur = A[i];
            i++;
        }else{
            cur = B[j];
            j++;
        }
        k++;
        if(k == sz){
            return cur;
        }
    }
    return cur;
}

//*************************************************//

static int findMid1(int * A,int * B,int sz){
    int a_left = 0;
    int a_right = sz -1;
    int b_left = 0;
    int b_right = sz -1;
    int a_mid = (a_left + a_right)/2;
    int b_mid = (b_left + b_right)/2;
    
    if(A[a_mid] < B[b_mid]){ //去掉A左边的，B右边的，要求去掉的长度一致
        int count = a_mid - a_left;
        a_left = a_mid;
        b_right = b_right - count;
    }else if(B[b_mid] < A[a_mid]){//去掉B左边的，A右边的，要求去掉的长度一致
        
    }else{
        return A[a_mid];
    }
    return 0;
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

static void test0(int A[],int B[],int sz){
    printf("before:\nA = ");
    display(A,sz);
    printf(",\n B = ");
    display(B, sz);
    printf("\nafter: mid = %d\n",findMid(A,B,sz));
}
static void test1(){
    int A[] = {11,13,15,17,19};
    int B[] = {2,4,6,8,20};
    int sz = sizeof(A)/sizeof(A[0]);
    test0(A,B,sz);
}

static void test2(){
    int A[] = {1,3,5,7};
    int B[] = {2,4,6,8};
    int sz = sizeof(A)/sizeof(A[0]);
    test0(A,B,sz);
}

int main(){
   test1();
   test2();
   return 0;
}
