//
//  DoubleLinkList.c
//  Data_Structure
//
//  Created by CC on 2021/3/1.
//  Copyright © 2021 CC. All rights reserved.
//

#include <stdio.h>

typedef int ElemType;

typedef struct DNode{
    ElemType data;
    struct DNode * next , * prev;
}DNode, * DLinkList;

//静态链表
#define MaxSize 50
typedef int ElemType;
typedef  struct{
    ElemType data;
    int next;
}SLinkList[MaxSize];
