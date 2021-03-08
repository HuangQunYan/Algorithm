//
//  T_03.c
//  Data_Structure
//
//  Created by CC on 2021/3/5.
//  Copyright © 2021 CC. All rights reserved.
//

/**
 利用一个栈实现以下递归函数的非递归计算;
  Rn(n,x) =
    if n = 0 ; return 1;
    if n = 1: return 2*x ;
    if n > 1 : return  2*x* Rn_1 - 2*(n-1)*Rn_2;
 */

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef struct{
    int n;
    double val;
}ElemType;

typedef struct Node{
    ElemType data;
    struct Node * next;
}Node;

typedef struct{
    Node * head;
}Stack;

Stack * stackCreate(){
    Stack * pStack= (Stack *)malloc(sizeof(Stack));
    
    Node * phead = (Node *)malloc(sizeof(Node));
    phead->next = NULL;
    
    pStack->head = phead;
    return pStack;
}


//清除pStack内用malloc 申请的资源
int stackDestroy(Stack * pStack){
    Node * p1 = pStack->head;
    Node * p2 = NULL;
    while(p1){
        p2 = p1->next;
        p1->next = NULL;
        free(p1);
        p1 = p2;
    }
    free(pStack);
    return 1;
}

int isEmpty(Stack * pStack){
    assert(pStack);
    assert(pStack->head);
    return pStack->head->next == NULL ? 1:0;
}

// 因为用的是链表，几乎不会有push不成功的
int push(Stack * pStack,ElemType x){
    assert(pStack);
    assert(pStack->head);
    //新加结点
    Node * p = (Node *)malloc(sizeof(Node));
    //初始化
    p->data = x;
    p->next = NULL;
    //入栈
    p->next = pStack->head->next;
    pStack->head->next = p;
    return 1;
}

// return{0,1} , 0-没有数据,pop失败，1-pop成功
int pop(Stack * pStack,ElemType * x){
    assert(pStack);
    assert(pStack->head);
    Node * p = pStack->head->next;
    if(p != NULL){
        *x = p->data;
        pStack->head->next = p->next;
        p->next = NULL;
        free(p);
        return 1;
    }
    return 0;
}

//****************************************************

double T_03_1(int n,double x){
    if(n == 0){
        return 1;
    }
    if(n == 1){
        return 2*x;
    }
    double Rn_2 = 1; //n = 0  //Pn-2
    double Rn_1 = 2*x; //n = 1 //Pn-1
    double Rn = 0; //n = 2 //Pn
    int i = 0;
    for(i = 2; i <= n;i++){
        Rn = 2*x*Rn_1 - 2*(n-1)*Rn_2;
        Rn_2 = Rn_1;
        Rn_1 = Rn;
    }
    return Rn;
}

double T_03(int n,double x){
    if(n == 0){
        return 1;
    }
    if(n == 1){
        return 2*x;
    }
    // n > 1
    Stack * pS = stackCreate();
    int i = 0;
    for(i = n; i > 1; i--){//n>=2
        ElemType Rn = {i,0.0};
        push(pS, Rn);
    }
    double Rn_2 = 1; // R n-2  一开始是 n = 0 的值
    double Rn_1 = 2*x; //R n-1 一开始是 n = 1 的值
    ElemType Rn;//R n 一开始是 n = 2的值
    while(pop(pS, &Rn)){
        Rn.val = 2*x*Rn_1 - 2*(n-1)*Rn_2;
        Rn_2 = Rn_1;
        Rn_1 = Rn.val;
    }
    stackDestroy(pS);
    return Rn.val;
}

int main(){
    printf("%lf\n",T_03_1(1, 2.0));
    printf("%lf\n",T_03_1(2, 2.0));
    printf("%lf\n",T_03_1(3, 2.0));
    printf("%lf\n",T_03_1(4, 2.0));
    printf("%lf\n",T_03_1(5, 2.0));
    
    printf("%lf\n",T_03(1, 2.0));
    printf("%lf\n",T_03(2, 2.0));
    printf("%lf\n",T_03(3, 2.0));
    printf("%lf\n",T_03(4, 2.0));
    printf("%lf\n",T_03(5, 2.0));
    return 0;
}


//4.000000
//14.000000
//32.000000
//4.000000
//-256.000000
//4.000000
//14.000000
//32.000000
//4.000000
//-256.000000
