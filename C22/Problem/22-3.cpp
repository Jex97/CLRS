// Euler tour
// O(E)
#include "common.h"

using namespace std;
/*
* u: 当前节点;
* path: 欧拉回路路径;
* G: 邻接表存储的图;
* isVisited: 该边是否已经被访问， 1是0否
*/
void euler(int u, stack<int>& path, const vector<vector<int>>& G, vector<vector<int>>& isVisited) {
	for (int i = 0; i < G[u].size(); ++i) {       // 可通过逆序遍历，每次把结尾的元素删除来减少不必要的判定；此时需去除G的const限制
		if (!isVisited[u][i]) {
			isVisited[u][i] = 1;
			euler(G[u][i], path, G, isVisited);
		}
	}
	path.push(u);
}
