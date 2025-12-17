// 实现了单个序列的运算
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int search(vector<int> &nums, int x) {
    int left = -1, right = nums.size();
    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (nums[mid] <= x)
            left = mid;
        else
            right = mid;
    }
    return left;
}
int main() {
    int n = 0;
    cin >> n;
    vector<int> nums_max(n);
    for (int i = 0; i < n; i++)
        cin >> nums_max[i];
    sort(nums_max.begin(), nums_max.end());
    vector<int> nums_min(n);
    for (int i = 0; i < n; i++)
        nums_min[i] = nums_max[i];
    while (nums_min.size() > 1) {
        int a = nums_min[nums_min.size() - 1];
        int b = nums_min[nums_min.size() - 2];
        nums_min.pop_back();
        nums_min.pop_back();
        nums_min.push_back(a * b + 1);
    }
    while (nums_max.size() > 1) {
        int a = nums_max[0];
        int b = nums_max[1];
        nums_max.erase(nums_max.begin());
        nums_max.erase(nums_max.begin());
        nums_max.insert(nums_max.begin() + search(nums_max, a * b + 1) + 1, a * b + 1);
    }
    int res = nums_max[0] - nums_min[0];
    cout << res << endl;
    return 0;
}
