//
//  Tree.c
//  Data_Structure
//
//  Created by CC on 2021/3/8.
//  Copyright © 2021 CC. All rights reserved.
//

#include <stdio.h>

typedef int ElemType;

typedef struct CSNode{
    ElemType data;
    struct CSNode * firstchild, * nextsibling;
}CSNode,*CSTree;
