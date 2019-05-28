//
// Created by dingmengdi on 2019/5/23.
//

#ifndef UNIONFIND_UNIONFINDTESTHELPER_H
#define UNIONFIND_UNIONFINDTESTHELPER_H

#include <iostream>
#include <ctime>

#include "UnionFind1.h"
#include "UnionFind2.h"


namespace UnionFindTestHelper{

    using namespace std;
    void testUF1(int n){
        srand(time(NULL));

        UF1::UnionFind uf = UF1::UnionFind(n);

        time_t startTime = clock();

        for (int i = 0; i < n; ++i) {
            int a = rand()%n;
            int b = rand()%n;
            uf.unionElements(a,b);
        }
        for (int i = 0; i < n; ++i) {
            int a = rand()%n;
            int b = rand()%n;
            uf.isConnected(a,b);
        }

        time_t endTime = clock();

        cout<<"UF1, "<< 2*n <<" ops, "<<double(endTime-startTime)/CLOCKS_PER_SEC<<"s"<<endl;
    }

    void testUF2(int n){
        srand(time(NULL));

        UF1::UnionFind2 uf = UF1::UnionFind2(n);

        time_t startTime = clock();

        for (int i = 0; i < n; ++i) {
            int a = rand()%n;
            int b = rand()%n;
            uf.unionElements(a,b);
        }
        for (int i = 0; i < n; ++i) {
            int a = rand()%n;
            int b = rand()%n;
            uf.isConnected(a,b);
        }

        time_t endTime = clock();

        cout<<"UF2, "<< 2*n <<" ops, "<<double(endTime-startTime)/CLOCKS_PER_SEC<<"s"<<endl;
    }
}




#endif //UNIONFIND_UNIONFINDTESTHELPER_H
