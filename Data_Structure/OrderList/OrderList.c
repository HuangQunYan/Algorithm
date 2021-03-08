//
//  main.c
//  Data_Structure
//
//  Created by CC on 2021/3/1.
//  Copyright © 2021 CC. All rights reserved.
//

#include <stdio.h>

#define MaxSize 50

typedef int ElemType;

//静态分配内存
typedef struct{
    ElemType data[MaxSize];
    int length;
}SqList;
    
    //动态内存分配
    //#define InitSize 100
    //
    //typedef int ElemType;
    //
    //typedef struct{
    //    ElemType * data;
    //    int MaxSize,length;
    //}SeqList;

    //L.data = (ElemType*)malloc(sizeof(ElemType)*InitSize);

int ListInsert(SqList * list,int i,ElemType e){
    if(i < 0 || i > list->length){ // 0< i < list->length
        return 0;
    }
    if(list->length >= MaxSize){ //当前存储空间
        return 0;
    }
    int j = 0;
    for(j = list->length; j > i; j--){
        list->data[j] = list->data[j-1];
    }
    list->data[i] = e;
    list->length++;
    return 1;
}

int ListDelete(SqList * list,int i,ElemType * e){
    if(i < 0 || i >= list->length){//判断i的范围是否有效
        return 0;
    }
    (*e) = list->data[i];
    int j = i;
    for( ; j < list->length - 1; j++){
        list->data[j] = list->data[j+1];
    }
    list->length--;
    return 1;
}

int LocateElem(const SqList * list, ElemType e){
    int i = 0;
    for(i = 0; i < list->length; i++){
        if(list->data[i] == e){
            return i;
        }
    }
    return -1;
}

void print(const SqList *list){
    int i = 0;
    printf("[");
    if(list->length > 0){
        printf(" %d ",list->data[0]);
    }
    for(i = 1; i < list->length; i++){
        printf(", %d ", list->data[i]);
    }
    printf("]\n");
}

int main(int argc, const char * argv[]) {
    SqList list ;
    int i = 0;
    for(i = 0; i < 10; i++){
        ListInsert(&list, i, i + 3);
    }
    print(&list);
    ElemType e = 0;
    if(ListDelete(&list,9, &e)){
        printf("delete index = %d, value = %d\n", 9, e);
    }
    print(&list);
    if(ListDelete(&list,6, &e)){
        printf("delete index = %d, value = %d\n", 6, e);
    }
    print(&list);
    e = 6;
    printf("value = %d index = %d\n", e,LocateElem(&list,e));
    return 0;
}
