//
//  T_03.c
//  Data_Structure
//
//  Created by CC on 2021/3/2.
//  Copyright © 2021 CC. All rights reserved.
//

//设L为带头结点的单链表，编写算法实现从尾到头反向输出每个结点的值

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node * next;
}Node,LinkList;

void _invertedOutput(Node * p){
    if(p){
        _invertedOutput(p->next);
        printf(" %d ->",p->data);
    }
}

void invertedOutput(LinkList * list){
    Node * first = list->next;
    _invertedOutput(first);
    printf("\n");
}


LinkList *  listInsert(){
    LinkList * list = (LinkList *)malloc(sizeof(Node));
    Node * prev = list;
    Node * curr = NULL;
    int x = 0;
    list->next = NULL;
    printf("输入999,退出。请输入:>");
    scanf("%d",&x);
    while(x != 999){
        curr = (Node *)malloc(sizeof(Node));
        curr->data = x;
        curr->next = NULL;
        prev->next = curr;
        prev = curr;
        printf("请输入:>");
        scanf("%d",&x);
    }
    return list;
}

void release(LinkList * list){
    Node * p;
    while(list){
        p = list->next;
        free(list);
        list = p;
    }
}

void display(const LinkList * list){
    Node *p = (Node *)list;
    while(p){
        printf(" %d ->", p->data);
        p = p->next;
    }
}

//也可用头插法,然后输出
void invertedOutput1(LinkList * list){
    Node * p = list->next; //第一个
    list->next = NULL;
    while(p){
        Node * q = p->next;
        p->next = list->next;
        list->next = p;
        p = q;
    }
    display(list->next);
}


void test1(){
    LinkList * list = listInsert();
    printf("list:");
    display(list->next);
    printf("\n");
    invertedOutput(list);
    printf("after:");
    display(list->next);
    printf("\n");
    release(list);
}

void test2(){
    LinkList * list = listInsert();
    printf("list:");
    display(list->next);
    printf("\n");
    printf("after:");
    invertedOutput1(list);
    printf("\n");
    release(list);
}

int main(){
    //test1();
    test2();
    return 0;
}


