#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
         _father = vector<int>(n, 0);
        //并查集初始化
        for (int i = 0; i < n; ++i) {
            _father[i] = i;
        }

        for (int i = 0; i < edges.size(); ++i) {
            join(edges[i][0], edges[i][1]);
        }
        return isSame(source, destination);
        
    }
                

private:
    vector<int> _father;
    //并查集寻根
    int find(int x) {
        return x == _father[x] ? x : _father[x] = find(_father[x]);
    }

    bool isSame(int u, int v) {
        u = find(u);
        v = find(v);
        return u == v;
    }

    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;//如果发现跟同，则说明在一个集合
        _father[v] = u;
    }

};