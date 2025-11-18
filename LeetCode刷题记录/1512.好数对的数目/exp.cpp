class Solution {
public:
    int combination_recursive(int n, int k) {
        if (k < 0 || k > n) return 0;
        if (k == 0 || k == n) return 1;

        return combination_recursive(n - 1, k - 1) + combination_recursive(n - 1, k);
    }
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> number_count;
        int res = 0;
        for (int i = 0;i < nums.size();i++) {
            if (number_count.find(nums[i]) != number_count.end()) number_count[nums[i]]++;
            else number_count.emplace(nums[i], 1);
        }
        for (auto it = number_count.begin();it != number_count.end();it++) {
            if (it->second >= 2) res += combination_recursive(it->second, 2);
        }
        return res;
    }
};
