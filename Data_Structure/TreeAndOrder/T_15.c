//
//  T_15.c
//  Data_Structure
//
//  Created by CC on 2021/3/8.
//  Copyright © 2021 CC. All rights reserved.
//

//设有一棵满二叉树（所有结点的值均不同）,已知其先序序列为pre，设计一个算法求其后序序列post

#include <stdio.h>
#include <string.h>

void _preToPost(char pre[],int pre_s,int pre_e,char post[], int post_s,int post_e){
    if(pre_s > pre_e){
        return;
    }
    post[post_e] = pre[pre_s];
    pre_s = pre_s + 1;
    post_e = post_e -1;
    //分成左右两堆
    int len = (pre_e - pre_s + 1) / 2;
    _preToPost(pre,pre_s, pre_s + len - 1,post,post_s,post_s + len -1);
    _preToPost(pre,pre_s + len, pre_e,post,post_s + len,post_e);
}

void preToPost(char pre[] , char post[],int sz){
    _preToPost(pre,0,sz-1,post,0,sz-1);

}

void test0(char pre[],int sz){
    int i = 0;
    char post[sz];
    for(i = 0; i < sz; i++){
        printf("%c", pre[i]);
    }
    printf("\n");
    preToPost(pre,post,sz);
    for(i = 0; i < sz; i++){
           printf("%c", post[i]);
    }
    printf("\n");
}

void test1(){
    char pre[] = "1245367";
    int len = (int)strlen(pre);
    test0(pre,len); //4526731
}

void test2(){
    char pre[] = "ABCDEFG";
    int len = (int)strlen(pre);
    test0(pre,len); //CDBFGEA
}

int main(){
    test1();
    test2();
    return 0;
}
