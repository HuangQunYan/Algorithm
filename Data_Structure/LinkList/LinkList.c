//
//  LinkList.c
//  Data_Structure
//
//  Created by CC on 2021/3/1.
//  Copyright © 2021 CC. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


typedef int ElemType;

typedef struct Node{ //将struct Node命名为Node
    ElemType data;
    struct Node * next;
}Node, * List; // 将 struct Node * 命名为List


List List_HeadInsert(List list){
    Node * s;
    int x;
    list = (List)malloc(sizeof(Node));
    list->next = NULL;
    scanf("%d",&x);
    while(x != 999){
        s = (Node *)malloc(sizeof(Node));
        s->data = x;
        s->next = list->next;
        list->next = s;
        scanf("%d",&x);
    }
    return list;
}

List List_TailInsert(List list){
    int x  = 0;
    Node * s = NULL, * r = NULL;
    list = (List)malloc(sizeof(Node));
    list->next = NULL;
    r = list;
    scanf("%d",&x);
    while(x != 999){
        s = (Node *)malloc(sizeof(Node));
        s->data = x;
        s->next = NULL;
        r->next = s;
        r = s;
        scanf("%d",&x);
    }
    return list;
}


Node * getElem(List list,int i){
    int j = 1;
    Node * p = list->next;
    if(i < 0){
        return NULL;
    }
    if(i == 0){
        return list;
    }
    while(p && j < i){
        p = p->next;
        j++;
    }
    return p;
}

Node * LocateElem(List list,ElemType e){
    Node * p = list->next;
    while(p != NULL && p->data != e){
        p = p->next;
    }
    return p;
}

int ListInsert(List list,ElemType e ,int i){
    Node * p = getElem(list, i-1);
    if(p == NULL){
        return 0;
    }
    Node * newN = (Node*)malloc(sizeof(Node));
    newN->data = e;
    newN->next = p->next;
    p->next = newN;
    return 1;
}

int ListInsertBefore(Node * p,ElemType e ,int i){
    Node * newN = (Node*)malloc(sizeof(Node));
    ElemType tmp;
    newN->data = e;
    newN->next = p->next;
    p->next = newN;
    tmp = p->data;
    p->data = newN->data;
    newN->data = tmp;
    return 1;
}

int ListDel(List list,int i){
    Node * p = getElem(list, i - 1); //前一个
    if(p == NULL){
        return 0;
    }
    Node * q = p->next;
    p->next = q->next;
    free(q);
    return 1;
}

