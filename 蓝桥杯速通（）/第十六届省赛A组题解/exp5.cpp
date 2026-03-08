// 这道题并没有AC，只能做到通过25%的测试用例
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int f(int n) {
    if (n == 1 || n == 0) {
        return 1;
    }
    return n * f(n - 1);
}
int main() {
    int sum = 0;
    cin >> sum;
    vector<int> element(sum);
    unordered_map<int, int> cnt;
    for (int i = 0; i < sum; i++) {
        cin >> element[i];
        if (cnt.find(element[i]) != cnt.end())
            cnt[element[i]]++;
        else
            cnt.emplace(element[i], 1);
    }
    int base = f(sum - 2);
    for (auto &e : cnt) {
        base /= f(e.second);
    }
    int ans = 0;
    for (auto &e : cnt) {
        int x = e.first;
        if ((sum - 2) % x == 0 && cnt.find((sum - 2) / x) != cnt.end()) {
            int y = (sum - 2) / x;
            if (x != y && cnt[x] >= 1 && cnt[y] >= 1) {
                ans = ans + (base * cnt[x] * cnt[y]);
            }
            if (x == y && cnt[x] >= 2) {
                ans = ans + (base * cnt[x] * (cnt[x] - 1));
            }
        }
    }
    cout << ans << endl;
    return 0;
}
