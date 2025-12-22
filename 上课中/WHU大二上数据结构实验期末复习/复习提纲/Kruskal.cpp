#include <bits/stdc++.h>
using namespace std;
// 并查集查询公共节点
int find_root(vector<int> &parent, int x) {
    if (parent[x] != x)
        parent[x] = find_root(parent, parent[x]);
    return parent[x];
}
int Kruskal(vector<vector<int>> &graph) {
    // 构造边数组，将图存入
    vector<vector<int>> edges;
    for (int i = 0; i < graph.size(); i++) {
        for (int j = i + 1; j < graph.size(); j++) {
            if (graph[i][j] != 0)
                edges.push_back({i, j, graph[i][j]});
        }
    }
    // 对边数组按照边权重排序
    sort(edges.begin(), edges.end(), [](const vector<int> &a, const vector<int> &b) { return a[2] < b[2]; });
    // 初始化并查集parent
    vector<int> parent(graph.size(), 0);
    for (int i = 0; i < graph.size(); i++) {
        parent[i] = i;
    }
    // 最小生成树的权值与判定
    int mst_weight = 0, flag = 0;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0], v = edges[i][1], weight = edges[i][2];
        int root_u = find_root(parent, u), root_v = find_root(parent, v);
        if (root_u != root_v) {
            mst_weight += weight;
            flag++;
            parent[root_u] = root_v;
        }
    }
    // 选取的边数不满足n-1条时，此时图没有最小生成树，返回-1
    if (flag != graph.size() - 1)
        return -1;

    return mst_weight;
}
int main() {
    // 建立图所对应的邻接矩阵作为算法输入，0代表无边，w代表有边与对应权重
    vector<vector<int>> graph = {{0, 3, 0, 0, 6, 5}, {3, 0, 1, 0, 0, 4}, {0, 1, 0, 6, 0, 4},
                                 {0, 0, 6, 0, 8, 5}, {6, 0, 0, 8, 0, 2}, {5, 4, 4, 5, 2, 0}};
    cout << Kruskal(graph) << endl;
    return 0;
}
