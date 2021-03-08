//
//  T_10.c
//  Data_Structure
//
//  Created by CC on 2021/3/1.
//  Copyright © 2021 CC. All rights reserved.
//

// 设将n(n>1)个整数存放到一维数组R中。设计一个在时间和空间两方面都尽可能高效的算法。
//将R中保存的序列循环左移p(0<p<n)个位置，即将R中的数据由(R0,R1,...Rp-1,Rp,Rp+1,...,Rn)变换成
//（Rp,Rp+1,...,Rn,R0,R1,...,Rp-1）

#include <stdio.h>

static void  ring_shift_left(int * arr,int sz, int p){
    int left = 0;
    int right = sz - 1;
    int tmp;
    for( ; left < right ; left++,right--){
        tmp = arr[left];
        arr[left] = arr[right];
        arr[right] = tmp;
    }
    for(left = 0,right = sz - p - 1; left < right; left++,right--){
        tmp = arr[left];
        arr[left] = arr[right];
        arr[right] = tmp;
    }
    for(left = sz - p,right = sz - 1; left < right; left++,right--){
        tmp = arr[left];
        arr[left] = arr[right];
        arr[right] = tmp;
    }
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

static void test1(){
    int arr[] = {0,1,2,3,4,5,6,7,8,9,10};
    int sz = sizeof(arr)/sizeof(arr[0]);
    int p = 5;
    printf("before:\n");
    display(arr,sz);
    ring_shift_left(arr, sz,p);
    printf("\nafter:\n");
    display(arr,sz);
    printf("\n");
}


int main(){
    test1();
    return 0;
}
