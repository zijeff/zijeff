class Solution {
  public:
    char find_root(unordered_map<char, char> &parent, char x) {
        if (parent[x] != x)
            parent[x] = find_root(parent, parent[x]);
        return parent[x];
    }
    bool equationsPossible(vector<string> &equations) {
        bool flag = true;
        unordered_map<char, char> parent;
        for (int i = 0; i < equations.size(); i++) {
            char x = equations[i][0], y = equations[i][3];
            if (parent.find(x) == parent.end())
                parent.emplace(x, x);
            if (parent.find(y) == parent.end())
                parent.emplace(y, y);
        }
        for (int i = 0; i < equations.size(); i++) {
            char x = equations[i][0], y = equations[i][3];
            char root_x = find_root(parent, x), root_y = find_root(parent, y);
            char key = equations[i][1];
            if (root_x != root_y && key == '=') {
                parent[root_x] = root_y;
            }
        }
        for (int i = 0; i < equations.size(); i++) {
            char x = equations[i][0], y = equations[i][3];
            char root_x = find_root(parent, x), root_y = find_root(parent, y);
            char key = equations[i][1];
            if (root_x == root_y && key == '!') {
                flag = false;
                break;
            }
        }
        return flag;
    }
};
