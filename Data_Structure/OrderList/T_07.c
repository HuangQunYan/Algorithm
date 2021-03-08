//
//  T_07.c
//  Data_Structure
//
//  Created by CC on 2021/3/1.
//  Copyright © 2021 CC. All rights reserved.
//

//将两个有序顺序表合并为一个新的有序顺序表，并由函数返回结果顺序表

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int * data;
    int length;
}SqList;


void merge(SqList * dest, const SqList * src1, const SqList * src2){
    int *  data = (int *)malloc(sizeof(int) * (src1->length + src2->length));
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < src1->length && j < src2->length){
        if(src1->data[i] <= src2->data[j]){
            data[k++] = src1->data[i++];
        }else{
            data[k++] = src2->data[j++];
        }
    }
    while(i < src1->length){
        data[k++] = src1->data[i++];
    }
    while(j < src2->length){
           data[k++] = src2->data[j++];
    }
    dest->data = data;
    dest->length = src1->length + src2->length;
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

void test0(int * A,int ASize, int * B,int BSize){
    SqList src1;
    listInit(&src1, A, ASize);
    SqList src2;
    listInit(&src2, B, BSize);
    SqList dest;
    printf("************************************\n");
    printf("before:\nsrc1:");
    display(&src1);
    printf("\nsrc2:");
    display(&src2);
    printf("\n");
    merge(&dest,&src1,&src2);
    printf("after:\n");
    display(&dest);
    printf("\n");
    free(dest.data);
}

void test1(){
    int A[] = {1,2,3,4,5};
    int ASize = sizeof(A)/sizeof(A[0]);
    int B[] = {3,3,4,5,6,8};
    int BSize = sizeof(B)/sizeof(B[0]);

    test0(A,ASize,B,BSize);
}

int main(){
    test1();
    return 0;
}


