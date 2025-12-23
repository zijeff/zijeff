// 使用邻接矩阵 + 优先队列 实现 Dijkstra 算法
#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

using ans = pair<int, vector<int>>; // [dist, path]

ans DijkstraPQ(vector<vector<int>> &graph, int begin, int end) {
    int n = graph.size();

    vector<int> dist(n, INF);
    vector<int> pre(n, -1);
    vector<bool> vis(n, false);

    // 小根堆 (dist, node)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[begin] = 0;
    pq.push({0, begin});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        // 堆中可能有过期状态
        if (vis[u])
            continue;
        vis[u] = true;

        // 松弛 u -> v
        for (int v = 0; v < n; v++) {
            if (!vis[v] && graph[u][v] < INF) {
                if (dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                    pre[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }
    }

    vector<int> path;
    if (dist[end] >= INF) {
        return {INF, path};
    }

    // 路径恢复
    int cur = end;
    while (cur != -1) {
        path.push_back(cur);
        cur = pre[cur];
    }
    reverse(path.begin(), path.end());

    return {dist[end], path};
}

int main() {
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

    ans res = DijkstraPQ(graph, 0, 7);
    cout << res.first << endl;
    for (int node : res.second)
        cout << node << ' ';
    cout << endl;
}
