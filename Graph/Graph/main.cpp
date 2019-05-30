#include <iostream>
#include <ctime>
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"
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

    string filename = "testG1.txt";
    SparseGraph g1(13, false);
    ReadGraph<SparseGraph> readGraph1(g1, filename);
}