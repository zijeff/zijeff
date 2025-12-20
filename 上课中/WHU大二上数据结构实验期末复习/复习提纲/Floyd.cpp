// 使用邻接矩阵实现Floyd算法
#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
using ans = pair<int, vector<int>>; // 定义返回的结果，即[dist, path]
ans Floyd(vector<vector<int>> &graph, int begin, int end) {
    // 初始化距离矩阵与路径矩阵
    vector<vector<int>> dist(graph.size(), vector<int>(graph.size(), 0));
    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph.size(); j++) {
            if (j != i)
                dist[i][j] = graph[i][j];
        }
    }
    vector<vector<int>> pre(graph.size(), vector<int>(graph.size(), -1));
    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph.size(); j++) {
            if (graph[i][j] < INF && i != j) {
                pre[i][j] = i; // 如果i→j直接可达，前驱是i
            }
        }
    }
    // 运行Floyd算法
    for (int k = 0; k < graph.size(); k++) {
        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph.size(); j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    pre[i][j] = pre[k][j];
                }
            }
        }
    }
    // 取出对应的结果
    vector<int> path;
    if (dist[begin][end] >= INF) {
        return {INF, path}; // 不可达
    }
    int cur = end;
    while (cur != -1) {
        path.push_back(cur);
        cur = pre[begin][cur];
    }
    // 反转路径（从起点到终点的顺序）
    reverse(path.begin(), path.end());
    return {dist[begin][end], path};
}
int main() {
    // 使用邻接矩阵存储图
    vector<vector<int>> graph = {
        // 0    1    2    3    4    5    6    7
        {0, 3, 5, INF, INF, INF, INF, INF}, // 0
        {3, 0, 1, 6, INF, INF, INF, INF},   // 1
        {5, 1, 0, 2, 4, INF, INF, INF},     // 2
        {INF, 6, 2, 0, 1, 7, INF, INF},     // 3
        {INF, INF, 4, 1, 0, 3, 5, INF},     // 4
        {INF, INF, INF, 7, 3, 0, 2, 6},     // 5
        {INF, INF, INF, INF, 5, 2, 0, 1},   // 6
        {INF, INF, INF, INF, INF, 6, 1, 0}  // 7
    };
    ans res = Floyd(graph, 0, 7);
    cout << res.first << endl;
    for (auto node : res.second)
        cout << node << ' ';
    cout << endl;
}
