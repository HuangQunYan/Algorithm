//
//  T_13.c
//  Data_Structure
//
//  Created by CC on 2021/3/8.
//  Copyright © 2021 CC. All rights reserved.
//

//设一棵二叉树的结点结构为(LLink,INFO,RLINK),ROOT为指向该二叉树根结点的指针
//p 和 q分别为指向该二叉树中任意两个结点的指针，试编写算法ANCESTER(ROOT,p,q,r),
//找到p和q的最近公共祖先结点r。

#include <stdio.h>

#define MaxSize 50

typedef struct BiTNode{
    int INFO;
    struct BiTNode * LLINK, * RLINK;
}BiTNode, BiTree;

typedef struct{
    BiTNode * data[MaxSize];
    int top;
}Stack;

    //假设栈的空间足够大,实际上可用链栈
    //后序非递归方式
int ANCESTER(BiTree * ROOT,BiTNode * p, BiTNode * q, BiTNode * r){
    Stack stack = {{0},-1};
    //先找出x;
    BiTNode * ptmp = ROOT;
    BiTNode * lastVisit = NULL;
    while(ptmp != NULL || stack.top != -1){
        if(ptmp != NULL){
            //begin 处理入的,可删，但加上会少走一些弯路
            if(p == ptmp){
                if(stack.top == -1){
                    return 0;
                }
                p = stack.data[stack.top];
            }
            if(q == ptmp){
                if(stack.top == -1){
                    return 0;
                }
                q = stack.data[stack.top];
            }
            if(p == q){
                *r = *p;
                return 1;
            }
            //end 处理入的
            stack.data[++stack.top] = ptmp;
            ptmp = ptmp->LLINK;
            continue;
        }
        //p为NULL时
        ptmp = stack.data[stack.top--];
        if(ptmp->RLINK == NULL || ptmp->RLINK == lastVisit){
            // visit(p);
            //begin 处理出的
            if(p == ptmp){
                if(stack.top == -1){
                    return 0;
                }
                p = stack.data[stack.top];
            }
            if(q == ptmp){
                if(stack.top == -1){
                    return 0;
                }
                q = stack.data[stack.top];
            }
            if(p == q){
                *r = *p;
                return 1;
            }
            //end 处理出的
            
            lastVisit = ptmp;
            ptmp = NULL;
        }else{//p->RLINK != NULL && p->RLINK != lastVisit
            stack.data[++stack.top] = ptmp;
            ptmp = ptmp->RLINK;
        }
    }
    return 0;//估计是Root为空，或p或q为空 //or root 中没有p或q
}

void test0(){
    BiTNode N1 = {1,NULL,NULL};
    BiTNode N2 = {2,NULL,NULL};
    BiTNode N3 = {3,NULL,NULL};
    BiTNode N4 = {4,NULL,NULL};
    BiTNode N5 = {5,NULL,NULL};
    BiTNode N6 = {6,NULL,NULL};

    N1.LLINK = &N2;
    N1.RLINK = &N3;

    N2.LLINK = &N4;
    N2.RLINK = &N5;

    N3.LLINK = &N6;
    
    BiTNode r ;
    int result;
    result = ANCESTER(&N1, &N4,&N5, &r);
    printf("latest ansestor of %d and %d is %d\n",N4.INFO,N5.INFO, (result == 1 ? r.INFO : -1 ));
    result = ANCESTER(&N1, &N4,&N6, &r);
    printf("latest ansestor of %d and %d is %d\n",N4.INFO,N6.INFO, (result == 1 ? r.INFO : -1 ));
    result = ANCESTER(&N1, &N4,&N2, &r);
    printf("latest ansestor of %d and %d is %d\n",N4.INFO,N2.INFO, (result == 1 ? r.INFO : -1 ));
    result = ANCESTER(&N1, &N1,&N2, &r);
    printf("latest ansestor of %d and %d is %d\n",N1.INFO,N2.INFO, (result == 1 ? r.INFO : -1 ));
    result = ANCESTER(&N1, &N3,NULL, &r);
    printf("latest ansestor of %d and NULL is %d\n",N3.INFO, (result == 1 ? r.INFO : -1 ));
   
}

void test1(){
    test0();
}

int main(){
    test1();
    return 0;
}
