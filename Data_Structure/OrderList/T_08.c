//
//  T_08.c
//  Data_Structure
//
//  Created by CC on 2021/3/1.
//  Copyright © 2021 CC. All rights reserved.
//

//已知在一维数组A[m+n]中依次存放两个线性表(a1,a2,a3,...,am)和(b1,b2,b3,...,bn),试编写一个函数
//将数组中两个顺序表的位置互换，即将(b1,b2,b3,...,bn)放在(a1,a2,a3,...,am)的前面.

#include <stdio.h>

void reverse(int * arr,int m,int n){
    int left = 0;
    int right = m + n -1;
    int tmp = 0;
    while(left < right){
        tmp = arr[left];
        arr[left] = arr[right];
        arr[right] = tmp;
        left++;
        right--;
    }
    //交换前n个
    left = 0;
    right = n-1;
    while(left < right){
       tmp = arr[left];
       arr[left] = arr[right];
       arr[right] = tmp;
       left++;
       right--;
    }
    //交换后m个
    left = n;
    right = m + n - 1;
    while(left < right){
       tmp = arr[left];
       arr[left] = arr[right];
       arr[right] = tmp;
        left++;
        right--;
    }
}

void display(const int * arr,int sz){
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

void test1(){
    int arr[] = {1,2,3,4,5,6,7,8,9,0};
    int sz = sizeof(arr)/sizeof(arr[0]);
    int m = 4;
    int n = sz - m;
    printf("before:\n");
    display(arr,sz);
    reverse(arr, m, n);
    printf("\nafter:\n");
    display(arr,sz);
    printf("\n");
}


int main(){
    test1();
    return 0;
}
