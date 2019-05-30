#include <iostream>
#include <ctime>
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"
#include "Component.h"
#include "Path.h"
int main() {

//     int N = 20;
//     int M = 100;
//
//     srand(time(NULL));
//
//     SparseGraph g1(N, false);
//    for (int i = 0; i < M; ++i) {
//        int a = rand()%N;
//        int b = rand()%N;
//        g1.addEdge(a,b);
//    }
//    for (int v = 0; v < N; ++v) {
//        cout<<v<<" : ";
//        SparseGraph::adjIterator adj(g1, v);
//
//        for (int w = adj.begin(); !adj.end(); w = adj.next())
//            cout<<w<<" ";
//        cout<<endl;
//    }
//
//
//    DenseGraph g2(N, false);
//    for (int i = 0; i < M; ++i) {
//        int a = rand()%N;
//        int b = rand()%N;
//        g2.addEdge(a,b);
//    }
//    for (int v = 0; v < N; ++v) {
//        cout<<v<<" : ";
//        DenseGraph::adjIterator adj2(g2, v);
//
//        for (int w = adj2.begin(); !adj2.end(); w = adj2.next())
//            cout<<w<<" ";
//        cout<<endl;
//    }

//    string filename = "testG1.txt";
//    SparseGraph g1(13, false);
//    ReadGraph<SparseGraph> readGraph1(g1, filename);
////    g1.show();
//    Component<SparseGraph> component1(g1);
//    cout<<"TestG1.txt, Component Count: " <<component1.count()<<endl;
//    cout<<component1.isConnected(1,3)<<endl;
//
//
//    string filename2 = "TestG2.txt";
//    DenseGraph g2(6, false);
//    ReadGraph<DenseGraph> readGraph2(g2, filename2);
////    g2.show();
//    Component<DenseGraph> component2(g2);
//    cout<<"TestG2.txt, Component Count: " <<component2.count()<<endl;

    string filename = "testG2.txt";
    SparseGraph g1(6, false);
    ReadGraph<SparseGraph> readGraph1(g1, filename);
    g1.show();
    Path<SparseGraph> path1(g1,0);
    path1.showPath(5);
}