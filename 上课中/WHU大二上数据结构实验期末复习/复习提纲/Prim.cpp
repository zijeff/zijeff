#include <bits/stdc++.h>
using namespace std;

int Prim(vector<vector<int>> &graph) {
    int n = graph.size();
    // 检查图是否为空
    if (n == 0) {
        return 0;
    }

    // 标记顶点是否在最小生成树中
    vector<bool> inMST(n, false);
    // 存储每个顶点到当前最小生成树的最小边权重
    vector<int> minWeight(n, INT_MAX);

    // 使用最小堆优化，存储{权重, 顶点}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    // 从顶点0开始构建最小生成树
    minWeight[0] = 0;
    minHeap.push({0, 0});
    int mst_weight = 0;
    int visited_count = 0;

    while (!minHeap.empty() && visited_count < n) {
        // 获取当前最小权重的顶点
        int weight = minHeap.top().first;
        int u = minHeap.top().second;
        minHeap.pop();

        // 如果顶点已经在MST中，跳过
        if (inMST[u] == true) {
            continue;
        }

        // 将该顶点加入MST
        inMST[u] = true;
        mst_weight += weight;
        visited_count++;

        // 更新与新加入顶点相邻的顶点到MST的最小权重
        for (int v = 0; v < n; v++) {
            // 条件1：顶点v不在MST中
            // 条件2：u和v之间存在边
            // 条件3：当前边的权重小于v已有的最小权重
            if ((inMST[v] == false) && (graph[u][v] != 0) && (graph[u][v] < minWeight[v])) {
                minWeight[v] = graph[u][v];
                minHeap.push({graph[u][v], v});
            }
        }
    }

    // 如果访问的顶点数不等于总顶点数，说明图不连通
    if (visited_count != n) {
        return -1;
    }

    return mst_weight;
}

int main() {
    // 建立图所对应的邻接矩阵作为算法输入，0代表无边，w代表有边与对应权重
    vector<vector<int>> graph = {{0, 3, 0, 0, 6, 5}, {3, 0, 1, 0, 0, 4}, {0, 1, 0, 6, 0, 4},
                                 {0, 0, 6, 0, 8, 5}, {6, 0, 0, 8, 0, 2}, {5, 4, 4, 5, 2, 0}};
    cout << Prim(graph) << endl;
    return 0;
}
