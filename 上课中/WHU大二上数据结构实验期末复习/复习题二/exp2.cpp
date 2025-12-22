#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    char data;
    TreeNode *child;
    TreeNode *brother;
};
void bfs(vector<vector<int>> &graph, vector<int> &vis, int begin) {
    queue<int> q;
    int current = begin;
    q.push(current);
    while (!q.empty()) {
        current = q.front();
        vis[current] = 1;
        q.pop();
        for (int i = 0; i < graph.size(); i++) {
            if (graph[current][i] == 1 && vis[i] != 1) {
                q.push(i);
            }
        }
    }
}
int get_edge_num(vector<vector<int>> &graph) {
    int res = 0;
    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph.size(); j++) {
            if (graph[i][j] == 1)
                res++;
        }
    }
    res = res / 2;
    return res;
}
bool judge(vector<vector<int>> &graph) {
    // 检验图的连通性
    vector<int> vis(graph.size(), 0);
    bfs(graph, vis, 0);
    for (int j = 0; j < vis.size(); j++) {
        if (vis[j] == 0)
            return false;
    }
    // 确保边数 = 顶点数 - 1
    if (get_edge_num(graph) != graph.size() - 1)
        return false;

    return true;
}
void build_tree(TreeNode *root, int begin, vector<vector<int>> &graph) {
    root->data = 'A' + begin;
    root->child = nullptr;
    root->brother = nullptr;
    queue<TreeNode *> q;
    TreeNode *current = root;
    q.push(current);
    while (!q.empty()) {
        int num = current->data - 'A';
        current = q.front();
        q.pop();
        int chd = 0;
        for (int i = 0; i < graph.size(); i++) {
            if (graph[num][i] == 1) {
                chd = i;
            }
        }
    }
}
int main() {
    // 建立图所对应的邻接矩阵作为算法输入，0代表无边，1代表有边
    vector<vector<int>> graph = {{0, 1, 0, 1, 1, 0, 0, 0}, {1, 0, 1, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0, 0, 0},
                                 {1, 0, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 1, 1, 1}, {0, 0, 0, 0, 1, 0, 0, 0},
                                 {0, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0}};
    bool flag = judge(graph);
    cout << flag << endl;
    if (flag == true) {
        TreeNode *root = nullptr;
        build_tree(root, 0);
    }
    return 0;
}
