// 气笑了，写Dijkstra写成SPFA了，都能跑出正确结果，但是算法思想不一样。所以也放在这供于参考。
#include <bits/stdc++.h>
using namespace std;
using edge = pair<int, int>;
struct cmp {
    bool operator()(const edge &a, const edge &b) const { return a.second > b.second; }
};
vector<int> Based_priority_queue_SPFA(vector<vector<edge>> &graph, int begin) {
    vector<int> dist(graph.size(), INT_MAX);
    priority_queue<edge, vector<edge>, cmp> s;
    dist[begin] = 0;
    edge current = {begin, 0};
    s.push(current);
    while (!s.empty()) {
        current = s.top();
        s.pop();
        for (auto &e : graph[current.first]) {
            if (dist[current.first] + e.second < dist[e.first]) {
                dist[e.first] = dist[current.first] + e.second;
                s.push({e.first, e.second});
            }
        }
    }
    return dist;
}
int main() {
    vector<vector<pair<int, int>>> graph(7);

    // 从 0 出发
    graph[0].push_back({1, 1});
    graph[0].push_back({2, 1});
    graph[0].push_back({3, 10});

    // 从 1 出发
    graph[1].push_back({2, 1});
    graph[1].push_back({6, 100});

    // 从 2 出发
    graph[2].push_back({3, 1});

    // 从 3 出发
    graph[3].push_back({4, 1});

    // 从 4 出发
    graph[4].push_back({5, 1});

    // 从 5 出发
    graph[5].push_back({6, 1});

    vector<int> dist = Based_priority_queue_SPFA(graph, 0);

    for (int i = 0; i < dist.size(); i++) {
        cout << "dist[0 -> " << i << "] = " << dist[i] << endl;
    }
}
