#include <iostream>
#include <cassert>
#include "UnionFindTestHelper.h"
using namespace std;


int main() {
//    UnionFind unionFind = UnionFind(5);
//
//    cout<<unionFind.isConnected(1,2)<<endl;
//    unionFind.unionElements(1,2);
//    cout<<unionFind.isConnected(1,2)<<endl;
//    cout<<endl;
//
//    cout<<unionFind.isConnected(1,3)<<endl;
//    cout<<unionFind.isConnected(2,3)<<endl;
//    unionFind.unionElements(1,3);
//    cout<<unionFind.isConnected(1,3)<<endl;
//    cout<<unionFind.isConnected(2,3)<<endl;
    UnionFindTestHelper::testUF1(100000);
    UnionFindTestHelper::testUF2(100000);
}