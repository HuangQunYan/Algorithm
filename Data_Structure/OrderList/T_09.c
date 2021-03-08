//
//  T_09.c
//  Data_Structure
//
//  Created by CC on 2021/3/1.
//  Copyright © 2021 CC. All rights reserved.
//

//线性表(a1,a2,a3,...,an)中的元素递增有序且按顺序存储于计算机内。
//要求设计一算法，完成用最少时间在表中查找数值为x的元素，若找到则将其后继元素位置相交换，
//若找不到则将其插入表中并使表中元素仍递增有序。

#include <stdio.h>

typedef struct{
    int * data;
    int length;
}SqList;

void T_09(SqList * list,int target){
    int left = 0;
    int right = list->length -1;
    int findIndex = -1;
    while(left <= right){
       int mid = (left + right)/2;
        if(list->data[mid] == target){//找到了
            findIndex = mid;
            break;
        }else if(list->data[mid] > target){//要在左边找
            right = mid -1;
        }else{
            left = mid + 1;
        }
    }//while(left <= right)
    //最终插入位置是left
    if(findIndex != -1 && findIndex < list->length - 1){//找到了
        list->data[findIndex] = list->data[findIndex + 1];
        list->data[findIndex + 1] = target;
        return ;
    }
    for(right = list->length; right > left; right--){
        list->data[right] = list->data[right -1];
    }
    list->data[left] = target;
    list->length +=1;
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

void test1(){
    int arr[] = {1,2,3,4,6,7,8,9,10,0,0,0};
    int sz = sizeof(arr)/sizeof(arr[0]);
    int target = 5;
    SqList list;
    listInit(&list, arr, sz - 3);
    printf("before:\n");
    display(&list);
    T_09(&list,target);
    printf("\nafter:\n");
    display(&list);
    printf("\n");

    printf("before:\n");
    display(&list);
    T_09(&list,target);
    printf("\nafter:\n");
    display(&list);
}

int main(){
    test1();
    return 0;
}

