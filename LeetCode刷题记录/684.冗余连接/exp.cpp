class Solution
{
public:
    int find_root(vector<int> &parent, int x)
    {
        if (parent[x - 1] != x)
        {
            parent[x - 1] = find_root(parent, parent[x - 1]);
        }
        return parent[x - 1];
    }
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        vector<int> result(2);
        vector<int> parent;
        for (int i = 0; i < edges.size(); i++)
        {
            parent.push_back(i + 1);
        }
        for (int i = 0; i < edges.size(); i++)
        {
            int x = edges[i][0], y = edges[i][1];
            int root_x = find_root(parent, x), root_y = find_root(parent, y);
            if (root_x == root_y)
                result = {x, y};
            else
                parent[root_x] = root_y;
        }
        return result;
    }
};
