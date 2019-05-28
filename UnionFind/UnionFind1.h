//
// Created by dingmengdi on 2019/5/23.
//

#ifndef UNIONFIND_UNIONFIND2_H
#define UNIONFIND_UNIONFIND2_H

#include <cassert>
#include <iostream>

namespace UF1{
    class UnionFind{

    private:
        int* id;
        int count;

    public:
        UnionFind(int n){
            count = n;
            id = new int[n];
            for (int i = 0; i < n; ++i) {
                id[i] = i;
            }
        }

        ~UnionFind(){
            delete[] id;
        }

        int find(int p){
            assert(p>=0 && p <count);
            return id[p];
        }

        bool isConnected(int p, int q){
            return find(p) == find(q);
        }

        void unionElements(int p, int q){
            int pId = find(p);
            int qId = find(q);
            if (qId == pId)
                return;
            for (int i = 0; i < count; ++i) {
                if (id[i] == pId)
                    id[i] = qId;
            }
        }
    };

    class UnionFind2 {
        int *parent;
        int count;

    public:
        UnionFind2(int count) {
            parent = new int[count];
            this->count = count;

            for (int i = 0; i < count; ++i) {
                parent[i] = i;
            }
        }

        ~UnionFind2() {
            delete[] parent;
        }


        int find(int p) {
            assert(p >= 0 && p < count);
            while (p != parent[p])
                p = parent[p];

            return p;
        }

        bool isConnected(int p, int q) {
            return find(p) == find(q);
        }

        void unionElements(int q, int p) {
            int pRoot = find(p);
            int qRoot = find(q);

            if (pRoot == qRoot)
                return;
            parent[pRoot] = qRoot;
        }

    };
}

#endif //UNIONFIND_UNIONFIND2_H
