//
// Created by Dingmengdi on 2019/5/6.
//
#include <iostream>

using namespace std;

#ifndef GRAPH_AMGRAPH_H
#define GRAPH_AMGRAPH_H


#define MaxInt 32767 //表示极大值
#define MVNum 100 //最大定点数
#define OK 1

typedef int Status;
typedef char VerTexType; //假设定点的数据类型为字符型
typedef int ArcType; //假设边的权值类型为整形

typedef struct {
    VerTexType vexs[MVNum]; //定点表
    ArcType arcs[MVNum][MVNum]; //邻接矩阵
    int vexnum,arcnum; //图的当前点数和边数
}AMGraph;


int LocateVex(AMGraph G, VerTexType v){

    for (int i = 0; i < MaxInt; ++i) {
        if (G.vexs[i] == v){
            return i;
        }
    }

    return -1;
}

Status GreateUDN(AMGraph &G){
    //采用邻接矩阵表示法，创建无向网G
    cin>>G.vexnum>>G.arcnum; //输入总定点数，总边数
    for (int i=0; i<G.vexnum; i++){ //依次输入顶点信息
        cin>>G.vexs[i];
    }

    for (int i = 0; i < G.vexnum; ++i) { //初始化邻接矩阵，边的权值
        for (int j=0; j<G.vexnum; j++){
            G.arcs[i][j] = MaxInt; //权值均为最大值
        }
    }

    char v1,v2;
    int w,i,j;
    for (int k = 0; k < G.arcnum; ++k) {
        cin>>v1>>v2>>w; //输入一条边依附的顶点和权值
        i = LocateVex(G,v1); //确定v1和v2的位置，即顶点数组的下标
        j = LocateVex(G,v2);
        G.arcs[i][j] = w;
        G.arcs[j][i] = G.arcs[i][j];

    }
    return OK;
}




#endif //GRAPH_AMGRAPH_H
