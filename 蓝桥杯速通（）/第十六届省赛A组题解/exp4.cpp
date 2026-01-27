#include <bits/stdc++.h>
using namespace std;
int count_1(int n, int k) {
    int cnt = 0;
    int num = k - 1;
    while (num != 0) {
        if (num % 2 == 1)
            cnt++;
        num = num / 2;
    }
    return cnt;
}
int main() {
    int m = 0;
    cin >> m;
    vector<vector<int>> n_k(m, vector<int>(2, 0));
    for (int i = 0; i < m; i++) {
        cin >> n_k[i][0] >> n_k[i][1];
    }
    for (int i = 0; i < m; i++) {
        int flag = count_1(n_k[i][0], n_k[i][1]);
        if (flag % 2 == 0)
            cout << "RED" << endl;
        else
            cout << "BLACK" << endl;
    }
    return 0;
}
