
/**
    1.假设一个算术表达式中包含圆括号、方括号和花括号3种类型的括号，编写一个算法来判别表达式中的括号是否配对，以字符'\0'作为算术表达式的结束符。
*/

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef char ElemType;

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


static char  match(char c){
        if(c == ')'){
            return  '(';
        }
        if(c == ']'){
            return  '[';
        }
        if(c == '}'){
            return  '{';
        }
        return '\0';
    }

static int T_01(Stack * pStack, char * str){
    char c;
    char c1;
    for(; (c = *(str)) != '\0';str++){
        if(c == '(' || c == '[' || c == '{'){
            push(pStack, c);
        }
        if(c == ')' || c == ']' || c == '}'){
            if(pop(pStack, &c1) == 0 || c1 != match(c)){
                return 0;
            }
        }
    }
    if(!isEmpty(pStack)){
        return 0;
    }
    return 1;
}

static void test0(char * pExp){
    Stack * pStack = stackCreate();
    if(T_01(pStack,pExp)){
        printf("%s,succ!\n",pExp);
    }else{
        printf("%s,fail!\n",pExp);
    }
    stackDestroy(pStack);
}

static void test1(){
    char * str = "(are){(you]}(crazy?}";
    test0(str);
}

static void test2(){
    char * str = "(No,){(I)am}(not)!";
    test0(str);
}

int main(){
    test1();
    test2();
    return 0;
}
