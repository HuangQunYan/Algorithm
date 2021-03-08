//
//  T_02.c
//  Data_Structure
//
//  Created by CC on 2021/3/2.
//  Copyright © 2021 CC. All rights reserved.
//

//在带头结点的单链表L中，删除所有值为x的结点，并释放其空间，假设值为x的结点不唯一，试编写算法以实现上述操作

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node * next;
}Node,LinkList;

static LinkList * delX(LinkList * list, int x){
    Node * prev = list;//头结点
    Node * p = list->next;//第一个数据结点
    while(p){
        if(p->data == x){
            prev->next = p->next;
            free(p);
        }else{
            prev = p;
        }
        p = p->next;
    }
    return list;
}

static LinkList *  listInsert(){
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

static void release(LinkList * list){
    Node * p;
    while(list){
        p = list->next;
        free(list);
        list = p;
    }
}

static void display(const LinkList * list){
    Node *p = (Node *)list;
    while(p){
        printf(" %d ->", p->data);
        p = p->next;
    }
}

static void test1(){
    LinkList * list = listInsert();
    int x= 0;
    printf("list:");
    display(list->next);
    printf("\n请输入x:>");
    scanf("%d",&x);
    delX(list, x);
    printf("after:");
    display(list->next);
    printf("\n");
    release(list);
}

int main(){
    test1();
    return 0;
}

