//
//  T_01.c
//  Data_Structure
//
//  Created by CC on 2021/3/1.
//  Copyright © 2021 CC. All rights reserved.
//

//设计一个递归算法，删除不带头结点的单链表L中所有值为x的结点;

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node * next;
}Node,LinkList;

Node * delX(Node * curr, int x){
    if(curr == NULL){
        return NULL;
    }
    if(curr->data == x){
        Node * p = curr->next;
        free(curr);
        return delX(p,x);
    }
    Node *p = curr->next;
    curr->next = delX(p,x);
    return curr;
    
}

LinkList *  listInsert(LinkList* *plist){
    Node * p = NULL;
    int x = 0;
    printf("输入999,退出输入,请输入:>");
    scanf("%d",&x);
    while(x != 999){
        p = (Node *)malloc(sizeof(Node));
        p->data = x;
        p->next = NULL;
        if(*plist == NULL){
            *plist = p;
        }else{
            p->next = *plist;
            *plist = p;
        }
        printf("请输入:>");
        scanf("%d",&x);
    }
    return *plist;
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

void test1(){
    LinkList * list = NULL;
    listInsert(&list);
    int x= 0;
    printf("list:");
    display(list);
    printf("\n请输入x:>");
    scanf("%d",&x);
    list = delX(list, x);
    printf("after:");
    display(list);
    printf("\n");
    release(list);
}

int main(){
    printf("hehe\n");
    test1();
    return 0;
}
