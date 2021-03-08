////
////  BiTree.c
////  Data_Structure
////
////  created by CC on 2021/3/6.
////  Copyright © 2021 CC. All rights reserved.
////
//
//#include <stdio.h>
//#include <assert.h>
//#include <stdlib.h>
//
//
//typedef struct BiTNode{
//    int data;
//    struct BiTNode * lchild, * rchild;
//}BiTNode,BiTree;
//
//void visit(BiTNode * pN){
//    printf(" %d ", pN->data);
//}
//
////递归代码
//
//void PreOrder(BiTree * T){
//    if(T != NULL){
//        visit(T);
//        PreOrder(T->lchild);
//        PreOrder(T->rchild);
//    }
//}
//
//void InOrder(BiTree * T){
//    if(T != NULL){
//        PreOrder(T->lchild);
//        visit(T);
//        PreOrder(T->rchild);
//    }
//}
//
//void PostOrder(BiTree * T){
//    if(T != NULL){
//        PostOrder(T->lchild);
//        PostOrder(T->rchild);
//        visit(T);
//    }
//}
//
////*****************************Stack start**************************************//
////链栈
////插头法 删头法
//
//typedef BiTNode * ElemType;
//
//typedef struct SNode{
//    ElemType data;
//    struct SNode * next;
//}SNode;
//
//typedef struct{
//    SNode * head;
//}Stack;
//
//Stack * stackCreate(){
//    Stack * pStack= (Stack *)malloc(sizeof(Stack));
//
//    SNode * phead = (SNode *)malloc(sizeof(SNode));
//    phead->next = NULL;
//
//    pStack->head = phead;
//    return pStack;
//}
//
//
//    //清除pStack内用malloc 申请的资源
//int stackDestroy(Stack * pStack){
//    SNode * p1 = pStack->head;
//    SNode * p2 = NULL;
//    while(p1){
//        p2 = p1->next;
//        p1->next = NULL;
//        free(p1);
//        p1 = p2;
//    }
//    free(pStack);
//    return 1;
//}
//
//int stackEmpty(Stack * pStack){
//    assert(pStack);
//    assert(pStack->head);
//    return pStack->head->next == NULL ? 1:0;
//}
//
//    // 因为用的是链表，几乎不会有push不成功的
//int push(Stack * pStack,ElemType x){
//    assert(pStack);
//    assert(pStack->head);
//    //新加结点
//    SNode * p = (SNode *)malloc(sizeof(SNode));
//    //初始化
//    p->data = x;
//    p->next = NULL;
//    //入栈
//    p->next = pStack->head->next;
//    pStack->head->next = p;
//    return 1;
//}
//
//    // return{0,1} , 0-没有数据,pop失败，1-pop成功
//int pop(Stack * pStack,ElemType * x){
//    assert(pStack);
//    assert(pStack->head);
//    SNode * p = pStack->head->next;
//    if(p != NULL){
//        *x = p->data;
//        pStack->head->next = p->next;
//        p->next = NULL;
//        free(p);
//        return 1;
//    }
//    return 0;
//}
////*************************Stack end*******************************//
//
////*************************非递归代码实现 start*******************************//
//
//void preOrder2(BiTree * T){
//    Stack * pS = stackCreate();
//    BiTNode * pTN = T;
//    while(pTN || !stackEmpty(pS)){
//        if(pTN != NULL){ //一路向左
//            visit(pTN);
//            push(pS, pTN);
//            pTN = pTN->lchild;
//            continue;
//        }
//        //pTN为空时
//        pop(pS, &pTN);
//        pTN = pTN->rchild;
//    }
//    stackDestroy(pS);
//}
//
//void inOrder2(BiTree * T){
//    Stack * pS = stackCreate();
//    BiTNode * pTN = T;
//    while(pTN || !stackEmpty(pS)){
//        if(pTN != NULL){
//            push(pS, pTN);
//            pTN = pTN->lchild;
//            continue;
//        }
//        //pTN为空时
//        pop(pS, &pTN);
//        visit(pTN);
//        pTN = pTN->rchild;
//    }
//    stackDestroy(pS);
//}
//
//void postOrder2(BiTree * T){
//    Stack * pS = stackCreate();
//    BiTNode * pTN = T;
//    BiTNode * lastVisit = NULL;
//    while(pTN || !stackEmpty(pS)){
//        if(pTN != NULL){
//            push(pS, pTN);
//            pTN = pTN->lchild;
//            continue;
//        }
//        //pTN为空时
//        pop(pS, &pTN);
//        if(pTN->rchild == NULL || lastVisit == pTN->rchild){
//            visit(pTN);
//            lastVisit = pTN;
//            pTN = NULL;
//        }else{//pTN->rchild != NULL && lastVisit != pTN->rchild
//            push(pS, pTN);
//            pTN = pTN->rchild;
//        }
//    }
//    stackDestroy(pS);
//}
//
////*************************非递归代码实现 end*******************************//
////************************** Queue start ***********************************//
//
//typedef struct QNode{
//    ElemType data;
//    struct QNode * next;
//}QNode;
//
// //插尾法，删头法
//typedef struct {
//    QNode * head; //头结点,出队的是head->next;
//    QNode * rear;
//}Queue;
//
//void queueDestroy(Queue * pQ){
//    assert(pQ);
//    assert(pQ->head);
//    QNode * p = pQ->head;
//    QNode * p1 = NULL;
//    while(p){
//        p1 = p->next;
//        p->next = NULL;
//        free(p);
//        p = p1;
//    }
//    free(pQ);
//}
//
//Queue * queueCreate(){
//    //建立头结点
//    Queue * pQ = (Queue *)malloc(sizeof(Queue));
//
//    QNode * pHead = (QNode*)malloc(sizeof(QNode));
//    pHead->next = NULL;
//
//    pQ->head = pQ->rear = pHead;
//    return pQ;
//}
//
//int queueEmpty(Queue *pQ){
//    return pQ->head == pQ->rear ? 1:0;
//}
//
//void enQueue(Queue * pQ,ElemType x){
//    assert(pQ);
//    assert(pQ->rear);
//
//    QNode * newN = (QNode *)malloc(sizeof(QNode));
//    newN->data =x;
//    newN->next = NULL;
//
//    pQ->rear->next = newN;
//    pQ->rear = newN;
//}
//
//int deQueue(Queue *pQ,ElemType * x){
//    assert(pQ);
//    assert(pQ->head);
//    if(pQ->head == pQ->rear){
//        return 0;
//    }
//    QNode * p = pQ->head->next;
//    pQ->head->next = p->next;
//    if(p == pQ->rear){
//        pQ->rear = pQ->head;
//    }
//    *x = p->data;
//    free(p);
//    return 1;
//}
//
////************************** Queue end ***********************************//
//
//void LevelOrder(BiTree * T){
//    Queue * pQ = queueCreate();
//    BiTree * pT = T;
//    enQueue(pQ, pT);
//    while(pQ){
//        deQueue(pQ, &pT);
//        visit(pT);
//        if(pT->lchild != NULL){
//            enQueue(pQ, pT->lchild);
//        }
//        if(pT->rchild != NULL){
//            enQueue(pQ, pT->rchild);
//        }
//    }
//}
