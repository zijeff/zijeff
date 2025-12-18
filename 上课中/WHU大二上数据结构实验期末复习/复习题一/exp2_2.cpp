// 实现了题目要求的对多个序列处理
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
int get_min(vector<int> &nums) {
    while (nums.size() > 1) {
        int a = nums[nums.size() - 1];
        int b = nums[nums.size() - 2];
        nums.pop_back();
        nums.pop_back();
        nums.push_back(a * b + 1);
    }
    return nums[0];
}
int get_max(vector<int> &nums) {
    while (nums.size() > 1) {
        int a = nums[0];
        int b = nums[1];
        nums.erase(nums.begin());
        nums.erase(nums.begin());
        nums.insert(nums.begin() + search(nums, a * b + 1) + 1, a * b + 1);
    }
    return nums[0];
}
vector<int> find_val(vector<vector<int>> nums) {
    vector<int> ans;
    for (auto num_max : nums) {
        sort(num_max.begin(), num_max.end());
        vector<int> num_min(num_max.size());
        for (int i = 0; i < num_max.size(); i++)
            num_min[i] = num_max[i];
        int res = get_max(num_max) - get_min(num_min);
        ans.push_back(res);
    }
    return ans;
}
int main() {
    int n = 0;
    cin >> n;
    vector<int> len(n);
    for (int i = 0; i < n; i++)
        cin >> len[i];
    vector<vector<int>> nums(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < len[i]; j++) {
            int e = 0;
            cin >> e;
            nums[i].push_back(e);
        }
    }
    vector<int> ans = find_val(nums);
    for (auto val : ans)
        cout << val << ' ';
    cout << endl;
    return 0;
}
