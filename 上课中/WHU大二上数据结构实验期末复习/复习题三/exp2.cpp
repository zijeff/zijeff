#include <bits/stdc++.h>
using namespace std;
void output(vector<int> &ans) {
    for (auto num : ans) {
        cout << num << ' ';
    }
    cout << endl;
}
struct Frame {
    vector<int> ans;
    int n;
    int i;
};
int main() {
    int n = 0;
    cin >> n;
    vector<int> ans(2 * n, 0);
    stack<Frame> s;
    Frame begin = {ans, n, 0};
    s.push(begin);
    while (!s.empty()) {
        Frame &f = s.top();
        if (f.n == 0) {
            output(f.ans);
            s.pop();
            continue;
        }
        if (f.i >= f.ans.size() - f.n - 1) {
            s.pop();
            continue;
        }
        int i = f.i;
        f.i++;
        if (f.ans[i] == 0 && f.ans[i + f.n + 1] == 0) {
            vector<int> next = f.ans;
            next[i] = f.n;
            next[i + f.n + 1] = f.n;
            s.push({next, f.n - 1, 0});
        }
    }
    return 0;
}
