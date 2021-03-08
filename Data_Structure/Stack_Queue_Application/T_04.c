//
//  T_04.c
//  Data_Structure
//
//  Created by CC on 2021/3/6.
//  Copyright © 2021 CC. All rights reserved.
//

//某汽车轮渡口，过江渡船每次都能载10辆汽车过江。过江车辆分为客车类和货车类，上渡船有如下规定：
//同类车先到先上船；客车先于货车上船，且每上4辆客车，才允许放上1辆货车；
//若等待客车不足4辆，则以货车代替；若无货车等待，允许客车都上船。试设计一个算法模拟渡口管理。
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef char ElemType;

typedef struct Node{
    ElemType data;
    struct Node * next;
}Node;

 //插尾法，删头法
typedef struct {
    Node * head; //头结点,出队的是head->next;
    Node * rear;
}Queue;

void queueDestroy(Queue * pQ){
    assert(pQ);
    assert(pQ->head);
    Node * p = pQ->head;
    Node * p1 = NULL;
    while(p){
        p1 = p->next;
        p->next = NULL;
        free(p);
        p = p1;
    }
    free(pQ);
}

void static queueDisplay(Queue * pQ){
    assert(pQ);
    assert(pQ->head);
    Node * p = pQ->head->next;
    while(p){
        printf(" %d ->", p->data);
        p = p->next;
    }
    printf("\n");
}

Queue * queueCreate(){
    //建立头结点
    Queue * pQ = (Queue *)malloc(sizeof(Queue));
    
    Node * pHead = (Node*)malloc(sizeof(Node));
    pHead->next = NULL;
    
    pQ->head = pQ->rear = pHead;
    return pQ;
}

int isEmpty(Queue *pQ){
    return pQ->head == pQ->rear ? 1:0;
}

void enQueue(Queue * pQ,ElemType x){
    assert(pQ);
    assert(pQ->rear);
    
    Node * newN = (Node *)malloc(sizeof(Node));
    newN->data =x;
    newN->next = NULL;
    
    pQ->rear->next = newN;
    pQ->rear = newN;
}

int deQueue(Queue *pQ,ElemType * x){
    assert(pQ);
    assert(pQ->head);
    if(pQ->head == pQ->rear){
        return 0;
    }
    Node * p = pQ->head->next;
    pQ->head->next = p->next;
    if(p == pQ->rear){
        pQ->rear = pQ->head;
    }
    *x = p->data;
    free(p);
    return 1;
}

//***********************************************************

Queue * T_04(Queue * qCars, Queue * pTrucks){
    Queue * qCross = queueCreate();
    int count = 0; //渡车的总数
    int i = 0; //每4辆客车，1辆货车
    ElemType c;
    while(count < 10){
        i = 0;
        while(count < 10 && i < 4 && deQueue(qCars, &c) ){
            enQueue(qCross,c);
            i++;
            count++;
        }
        if(count < 10 && deQueue(pTrucks, &c)){
            enQueue(qCross,c);
            count++;
        }
        if(isEmpty(qCars) && isEmpty(pTrucks)){
            break;
        }
    }
    return qCross;
}

//两者都不足
void test0(int carNums,int truckNums){
    Queue * pCars = queueCreate();
    Queue * pTrucks = queueCreate();
    int i = 0;
    char c = 0;
    for(i = 0; i < carNums; i++){
         enQueue(pCars, 'C');
    }
    for(i = 0; i < truckNums; i++){
        enQueue(pTrucks, 'T');
    }
   
    Queue * pCross =  T_04(pCars,pTrucks);
    while(deQueue(pCross, &c)){
        printf("%c ->", c);
    }
    printf("\n");
    queueDestroy(pCars);
    queueDestroy(pTrucks);
    queueDestroy(pCross);
}

void test1(){
    test0(5,1);
}

void test2(){
    test0(3,8);
}

void test3(){
    test0(10,1);
}

void test4(){
    test0(10,3);
}


int main(){
    test1();
    test2();
    test3();
    test4();
    return 0;
}
