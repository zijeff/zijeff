// 能够判断并且从给定的节点生成孩子兄弟链树
#include <bits/stdc++.h>
using namespace std;
// 定义树的结构体
struct TreeNode {
    char data;
    TreeNode *child;
    TreeNode *brother;

    TreeNode(char val) : data(val), child(nullptr), brother(nullptr) {};
    TreeNode(char val, TreeNode *left, TreeNode *right) : data(val), child(left), brother(right) {};
};
// bfs判断连通性
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
// 获取边的数目
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
// 由给定的根节点建立孩子兄弟链结构的树
TreeNode *build_tree(int u, int parent, vector<vector<int>> &graph) {
    TreeNode *node = new TreeNode('A' + u);
    TreeNode *lastChild = nullptr;
    for (int v = 0; v < graph.size(); v++) {
        if (graph[u][v] == 1 && v != parent) {
            TreeNode *child = build_tree(v, u, graph);
            if (node->child == nullptr) {
                node->child = child;
            } else {
                lastChild->brother = child;
            }
            lastChild = child;
        }
    }
    return node;
}
// 输出树，后序遍历
void out_behind(TreeNode *node) {
    if (node == nullptr)
        return;
    out_behind(node->child);
    out_behind(node->brother);
    cout << node->data << ' ';
}
int main() {
    // 建立图所对应的邻接矩阵作为算法输入，0代表无边，1代表有边
    vector<vector<int>> graph = {{0, 1, 0, 1, 1, 0, 0, 0}, {1, 0, 1, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0, 0, 0},
                                 {1, 0, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 1, 1, 1}, {0, 0, 0, 0, 1, 0, 0, 0},
                                 {0, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0}};
    bool flag = judge(graph);
    cout << flag << endl;
    if (flag == true) {
        TreeNode *root = build_tree(0, -1, graph);
        out_behind(root);
        cout << endl;
    }
    return 0;
}
