// 手搓第2025个质数
#include <bits/stdc++.h>
using namespace std;
bool is_prime(int n) {
    vector<bool> nums(n + 1, true);
    nums[0] = false;
    nums[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (nums[i] == true) {
            for (int j = i * i; j <= n; j += i) {
                nums[j] = false;
            }
        }
    }
    return nums[n];
}
int main() {
    int i = 0, res = 2;
    while (i < 2025) {
        if (is_prime(res) == true) {
            i++;
        }
        res++;
    }
    cout << res - 1 << endl;
    return 0;
}
