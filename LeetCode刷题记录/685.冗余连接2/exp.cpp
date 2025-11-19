class Solution
{
public:
    int find_root(vector<int> &parent, int x)
    {
        if (parent[x] != x)
            parent[x] = find_root(parent, parent[x]);
        return parent[x];
    }
    vector<int> no_have_2_degree(vector<vector<int>> &edges)
    {
        int n = edges.size();
        vector<int> ans(2);
        vector<int> parent(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
        for (int i = 0; i < n; i++)
        {
            int x = edges[i][0], y = edges[i][1]; // x->y
            int root_x = find_root(parent, x), root_y = find_root(parent, y);
            if (root_x == root_y)
                ans = {x, y};
            else
                parent[root_y] = root_x;
        }
        return ans;
    }
    bool is_tree(vector<vector<int>> &edges, int u, int v)
    {
        int n = edges.size();
        vector<int> parent(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
        for (int i = 0; i < n; i++)
        {
            int x = edges[i][0], y = edges[i][1]; // x->y
            if (x == u && y == v)
                continue;
            int root_x = find_root(parent, x), root_y = find_root(parent, y);
            if (root_x == root_y)
                return false;
            else
                parent[root_y] = parent[root_x];
        }
        return true;
    }
    vector<int> have_2_degree(vector<vector<int>> &edges, vector<int> &degree)
    {
        vector<int> ans(2);
        for (int i = edges.size() - 1; i >= 0; i--)
        {
            int x = edges[i][1];
            if (degree[x] == 2)
            {
                ans = {edges[i][0], edges[i][1]};
                if (is_tree(edges, edges[i][0], edges[i][1]))
                    break;
            }
        }
        return ans;
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        vector<int> result(2);
        vector<int> degree(n + 1);
        for (int i = 0; i < n; i++)
        {
            int x = edges[i][1];
            degree[x]++;
        }
        auto it = find(degree.begin(), degree.end(), 2);
        if (it != degree.end())
            result = have_2_degree(edges, degree);
        else
            result = no_have_2_degree(edges);
        return result;
    }
};
