//
// Created by Dingmengdi on 2019/5/31.
//

#ifndef MINIMUMSPANTREE_EDGE_H
#define MINIMUMSPANTREE_EDGE_H

#include <iostream>
#include <cassert>

using namespace std;

template <typename Weight>
class Edge{
    int a, b;
    Weight weight;

public:
    Edge(int a, int b, Weight weight){
        this->a = a;
        this->b = b;
        this->weight = weight;
    }

    Edge(){}

    ~Edge(){}

    int V(){ return a;}
    int W(){ return b;}
    Weight wt(){ return weight;}

    int other(int x){
        assert(x ==a || x == b);
        return x==a ? a:b;
    }

    friend ostream&operator<<(ostream &os, const Edge &e){
        os<<e.a<<"-"<<e.b<<": "<<e.weight;
        return os;
    }

    bool operator<(Edge<Weight>& e){
        return weight < e.wt();
    }

    bool operator<=(Edge<Weight>& e){
        return weight <= e.wt();
    }

    bool operator>(Edge<Weight>& e){
        return weight > e.wt();
    }

    bool operator>=(Edge<Weight>& e){
        return weight >= e.wt();
    }

    bool operator==(Edge<Weight>& e){
        return weight == e.wt();
    }
};


#endif //MINIMUMSPANTREE_EDGE_H
