//
// Created by Dingmengdi on 2019/5/8.
//

#ifndef TEST2_YANGHUI_H
#define TEST2_YANGHUI_H

#define MAXSIZE 100
#include <iostream>
using namespace std;
typedef int SElemType;
typedef struct
{
    SElemType *base;
    int front;
    int rear;
}Queue;
void InitQueue(Queue &Q)
{
    Q.base=new SElemType[MAXSIZE];
    Q.front=Q.rear=0;
}
int  EnQueue(Queue &Q,int e)
{
    if((Q.rear+1)%MAXSIZE==Q.front)
        return 0;
    Q.base[Q.rear]=e;
    Q.rear=(Q.rear+1)%MAXSIZE;
    return 1;
}
int Dequeue(Queue &Q,int &e)
{
    if(Q.rear==Q.front)
        return 0;
    e=Q.base[Q.front];
    Q.front=(Q.front+1)%MAXSIZE;
    return 1;
}
int yanghuisanjiao()
{
    int n;
    Queue Q;
    InitQueue(Q);
    cout<<"请输入需要打印多少行杨辉三角:"<<endl;
    cin>>n;

    for (int i = 0; i < n; ++i) {

        for (int j = 0; j < n-i-1; ++j) {
            cout<<" ";
        }

        if (i == 0){
            cout<<1<<endl;
            EnQueue(Q,1);
        }else{
            int t1=0;
            int t2=0;
            int e;
            for (int j = 0; j < i; ++j) {
                Dequeue(Q,e);
                t1 = t2;
                t2 = e;
                e = t1 + t2;
                cout<<e<<" ";
                EnQueue(Q,e);
            }
            e = 1;
            cout<<e<<endl;
            EnQueue(Q,e);
        }
    }
    return 1;
}


#endif //TEST2_YANGHUI_H
