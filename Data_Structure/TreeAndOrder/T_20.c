//
//  T_20.c
//  Data_Structure
//
//  Created by CC on 2021/3/8.
//  Copyright © 2021 CC. All rights reserved.
//

//将给定的表达式树（二叉树）转换为等价的中缀表达式（通过括号反映操作符的计算次序）并输出。

#include <stdio.h>

typedef struct BiTNode{
    char data[10];
    struct BiTNode * left,* right;
}BiTNode, BiTree;



//设最大深度不超过50,要是担心，可以链表实现stack,多加一个长度
void _T_20(BiTree * T){
    if(T == NULL){
        return;
    }
    if(T->left != NULL || T->right != NULL){
        printf("(");
        _T_20(T->left);
        printf("%s",T->data);
        _T_20(T->right);
        printf(")");
        return ;
    }
    printf("%s",T->data);
}

void T_20(BiTree * T){
    if(T == NULL){
        return;
    }
    _T_20(T->left);
    printf("%s",T->data);
    _T_20(T->right);
}

void test1(){
    BiTNode N1 = {{'*','\0'},NULL,NULL};
    BiTNode N2 = {{'+','\0'},NULL,NULL};
    BiTNode N3 = {{'*','\0'},NULL,NULL};
    BiTNode N4 = {{'a','\0'},NULL,NULL};
    BiTNode N5 = {{'b','\0'},NULL,NULL};
    BiTNode N6 = {{'c','\0'},NULL,NULL};
    BiTNode N7 = {{'-','\0'},NULL,NULL};
    BiTNode N8 = {{'d','\0'},NULL,NULL};

    N1.left = &N2;
    N1.right = &N3;

    N2.left = &N4;
    N2.right = &N5;

    N3.left = &N6;
    N3.right = &N7;
    
    N7.right = &N8;
    
    T_20(&N1);
    printf("\n");
}

void test2(){
    BiTNode N1 = {{'+','\0'},NULL,NULL};
    BiTNode N2 = {{'*','\0'},NULL,NULL};
    BiTNode N3 = {{'-','\0'},NULL,NULL};
    BiTNode N4 = {{'a','\0'},NULL,NULL};
    BiTNode N5 = {{'b','\0'},NULL,NULL};
    BiTNode N6 = {{'-','\0'},NULL,NULL};
    BiTNode N7 = {{'c','\0'},NULL,NULL};
    BiTNode N8 = {{'d','\0'},NULL,NULL};

    N1.left = &N2;
    N1.right = &N3;

    N2.left = &N4;
    N2.right = &N5;

    N3.right = &N6;
    
    N6.left = &N7;
    N6.right = &N8;
    
    T_20(&N1);
    printf("\n");
}



int main(){
    test1();
    test2();
    return 0;
}
