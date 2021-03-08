//
//  T_17.c
//  Data_Structure
//
//  Created by CC on 2021/3/8.
//  Copyright © 2021 CC. All rights reserved.
//

//试设计判断两棵二叉树是否相似的算法。所谓二叉树T1,T2相似，指的是T1和T2都是空的二叉树或都只有一个根结点；
//或T1的左子树和T2的左子树是相似的，且T1的右子树与T2的右子树是相似的.
//总结：就是判断树的形状是否相似

#include <stdio.h>

typedef struct BiTNode{
    int data;
    struct BiTNode * lchild, * rchild;
}BiTNode, BiTree;


     //一开始,head是为空
    // pre 是前继结点,一开始也为空
int similar(BiTree * T1, BiTree * T2){
    if(T1 == NULL && T2 == NULL){
        return 1;
    }
    if((T1 == NULL && T2 != NULL)||(T1 != NULL && T2 == NULL)){
        return 0;
    }
    //两边都不空
    return  similar(T1->lchild, T2->lchild) && similar(T1->rchild, T2->rchild);
}


void test0(){
    BiTNode N1 = {1,NULL,NULL};
    BiTNode N2 = {2,NULL,NULL};
    BiTNode N3 = {3,NULL,NULL};
    BiTNode N4 = {4,NULL,NULL};
    BiTNode N5 = {5,NULL,NULL};
    BiTNode N6 = {6,NULL,NULL};

    N1.lchild = &N2;
    N1.rchild = &N3;

   // N2.lchild = &N4;
    N2.rchild = &N5;

    N3.lchild = &N6;
    
    BiTNode T1 = {1,NULL,NULL};
    BiTNode T2 = {2,NULL,NULL};
    BiTNode T3 = {3,NULL,NULL};
    BiTNode T4 = {4,NULL,NULL};
    BiTNode T5 = {5,NULL,NULL};
    BiTNode T6 = {6,NULL,NULL};

    T1.lchild = &T2;
    T1.rchild = &T3;

    T2.lchild = &T4;
    T2.rchild = &T5;

    //T3.lchild = &T6;

    printf(" %d \n" , similar(&N1, &T1));
}


int main(){
    test0();
    return 0;
}
