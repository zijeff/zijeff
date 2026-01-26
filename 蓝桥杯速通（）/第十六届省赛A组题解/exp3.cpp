// 判断逻辑可能有点臃肿（）
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n = 0;
    cin >> n;
    vector<vector<int>> disks(3, vector<int>(n, 0));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            cin >> disks[i][j];
        }
    }
    int m = 0;
    cin >> m;
    vector<vector<int>> works(m, vector<int>(3, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> works[i][j];
        }
    }
    int sum = 0;
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < m; i++) {
        a = (a + works[i][0]) % n;
        b = (b + works[i][1]) % n;
        c = (c + works[i][2]) % n;
        // 三个相同图案
        if (disks[0][a] == disks[1][b] && disks[1][b] == disks[2][c])
            sum += 200;
        // 两个相同图案
        if (disks[0][a] == disks[1][b] && disks[1][b] != disks[2][c])
            sum += 100;
        if (disks[0][a] == disks[2][c] && disks[1][b] != disks[2][c])
            sum += 100;
        if (disks[1][b] == disks[2][c] && disks[0][a] != disks[2][c])
            sum += 100;
        // 对于连续的三个数
        if (disks[1][b] - disks[0][a] == 1 && disks[2][c] - disks[1][b] == 1) {
            sum += 200;
        } else {
            vector<int> temp = {disks[0][a], disks[1][b], disks[2][c]};
            sort(temp.begin(), temp.end());
            if (temp[1] - temp[0] == 1 && temp[2] - temp[1] == 1)
                sum += 100;
        }
    }
    cout << sum << endl;
    return 0;
}
