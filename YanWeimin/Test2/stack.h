//
// Created by Dingmengdi on 2019/4/24.
//
#include <iostream>
#include <string>
#include <sstream>
#ifndef TEST2_STACK_H
#define TEST2_STACK_H

#define OK 1
#define NULL 0
#define ERROR -2

typedef int Status;
typedef char CharElemType;
typedef int IntElemType;
//链栈的存储结构

typedef struct CharStackNode{
    CharElemType data;
    struct CharStackNode *next;
}CharStackNode, *CharLinkStack;
typedef struct IntStackNode{
    IntElemType data;
    struct IntStackNode *next;
}IntStackNode, *IntLinkStack;

//初始化栈
template <typename T>
Status InitStack(T &S){
    S = NULL;
    return OK;
}

//压入栈(字符)
Status CharPush(CharLinkStack &S, char e){
    CharLinkStack p = new CharStackNode;
    p->data=e;
    p->next=S;
    S=p;
    return OK;

}
//压入栈(整数)
Status IntPush(IntLinkStack &S, int e){
    IntLinkStack p = new IntStackNode;
    p->data=e;
    p->next=S;
    S=p;
    return OK;

}
//出栈（字符）
Status CharPOp(CharLinkStack &S, char &e){
    if(S == NULL){
        return ERROR;
    }
    e=S->data;
    CharLinkStack p = S;
    S=S->next;
    delete p;
    return OK;
}

//出栈（数字）
Status IntPOp(IntLinkStack &S, int &e){
    if(S == NULL){
        return ERROR;
    }
    e=S->data;
    IntLinkStack p = S;
    S=S->next;
    delete p;
    return OK;
}

//获取栈顶元素（字符）
CharElemType CharGetTop(CharLinkStack &S){
    if(S!=NULL){
        return S->data;
    }
}
//获取栈顶元素（数字）
IntElemType IntGetTop(IntLinkStack &S){
    if(S!=NULL){
        return S->data;
    }
}
using namespace std;

//判断是否是运算符
bool In(char c){
    string carr = "+-*/()#";
    for (int i = 0; i < carr.length(); ++i) {
        if(carr[i] == c){
            return true;
        }
    }
    return false;
}

//比较OPTR的栈顶元素和ch的优先级
char Precede(char o1, char o2){
    char t[7][7] = {
                  {'>','>','<','<','<','>','>'},

                  {'>','>','<','<','<','>','>'},

                  {'>','>','>','>','<','>','>'},

                  {'>','>','>','>','<','>','>'},

                  {'<','<','<','<','<','=',' '},

                  {'>','>','>','>',' ','>','>'},

                  {'<','<','<','<','<',' ','='},
                 };

    int i,j;
    switch (o1){
        case '+': i=0;break;
        case '-': i=1;break;
        case '*': i=2;break;
        case '/': i=3;break;
        case '(': i=4;break;
        case ')': i=5;break;
        case '#': i=6;break;
    }
    switch (o2){
        case '+': j=0;break;
        case '-': j=1;break;
        case '*': j=2;break;
        case '/': j=3;break;
        case '(': j=4;break;
        case ')': j=5;break;
        case '#': j=6;break;
    }
    return t[i][j];
}

//运算
int Operate(int a, char theta, int b){
    int result;
    switch (theta){
        case '+': result = a+b;break;
        case '-': result = a-b;break;
        case '*': result = a*b;break;
        case '/': result = a/b;break;
    }
    return result;
}

int EvaluateExpression(){
    IntLinkStack OPND; //操作数栈
    CharLinkStack OPTR; //运算符栈
    InitStack(OPND);
    InitStack(OPTR);
    CharPush(OPTR, '#'); //将表达式起始符号#压入OPTR栈

    char ch;
    cin>>ch;

    string chs = "";
    int ins;
    char theta,x;
    int a,b;
    while (ch !='#' || CharGetTop(OPTR) !='#'){
        if(!In(ch)){//如果ch不是运算符
            chs = chs + ch;
            cin>>ch;
        }else{
            if(chs != ""){
                stringstream ss;
                ss << chs;
                ss >> ins;
                IntPush(OPND, ins); //数字进入OPND栈
                chs = "";
            }
            switch (Precede(CharGetTop(OPTR),ch)){
                case '<':
                    CharPush(OPTR,ch);//当前字符ch压入OPTR栈，读取下一个字符
                    cin>>ch;
                    break;
                case '>':
                    CharPOp(OPTR,theta);
                    IntPOp(OPND,b);
                    IntPOp(OPND,a);
                    IntPush(OPND,Operate(a,theta,b));
                    break;
                case '=':
                    CharPOp(OPTR,x);
                    cin>>ch;
                    break;
            }
        }
    }
    return IntGetTop(OPND);
}

#endif //TEST2_STACK_H
