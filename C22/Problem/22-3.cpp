// Euler tour
// O(E)
#include "common.h"

/*
* u: 当前节点;
* path: 欧拉回路路径;
* G: 邻接表存储的图;
* isVisited: 该边是否已经被访问，1是0否;
*/
void euler(int u, vector<int>& path, const vector<vector<int>>& G, vector<vector<int>>& isVisited){
    for(int i = 0; i < G[u][i]; ++i){
        if(!isVisited[u][i]){
            isVisited[u][i] = 1;
            euler(G[u][i], path, G, isVisited);
        }
    }
    path.push_back(u);
}
