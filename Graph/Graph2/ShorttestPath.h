//
// Created by Dingmengdi on 2019/5/31.
//

#ifndef GRAPH2_SHORTTESTPATH_H
#define GRAPH2_SHORTTESTPATH_H

#include <queue>

template <typename Graph>
class ShortestPath {

private:
    Graph &G;
    int s;
    bool *visited;
    int *from;
    int *ord;

public:
    ShortestPath(Graph &graph, int s): G(graph){

        //算法的初始化
        assert(s >=0 && s < graph.V());

        visited = new bool[graph.V()];
        from = new int[graph.V()];
        ord = new int[graph.V()];

        for (int i = 0; i < graph.V(); ++i) {
            visited[i] = false;
            from[i] = -1;
            ord[i] = -1;
        }

        this->s = s;

        queue<int> q;

        //无向图最短路径算法
        q.push(s);
        visited[s] = true;
        ord[s] = 0;

        while (!q.empty()){
            int v = q.front();
            q.pop();

            typename Graph::adjIterator adj(G,v);
            for (int i = adj.begin(); !adj.end() ; i = adj.next()) {

                if (!visited[i]){
                    q.push(i);
                    visited[i] = true;
                    from[i] = v;
                    ord[i] = ord[v] + 1;
                }
            }
        }

    }

    ~ShortestPath(){
        delete [] visited;
        delete [] from;
        delete [] ord;
    }

    bool hasPath(int w){
        assert(w >= 0 && w < G.V());
        return visited[w];
    }

    void path(int w, vector<int> &vec){

        assert(w >= 0 && w < G.V());

        stack<int> s;

        int p = w;
        while (p != -1){
            s.push(p);
            p = from[p];
        }

        vec.clear();
        while (!s.empty()){
            vec.push_back(s.top());
            s.pop();
        }
    }

    void showPath(int w){
        assert(w >= 0 && w < G.V());

        vector<int> vec;
        path(w,vec);
        for (int i = 0; i < vec.size(); ++i) {
            cout<<vec[i];
            if (i == vec.size()-1)
                cout<<endl;
            else
                cout<<"->";
        }
    }

    int length(int w){
        assert(w >= 0 && w < G.V());

        return ord[w];
    }
};



#endif //GRAPH2_SHORTTESTPATH_H
