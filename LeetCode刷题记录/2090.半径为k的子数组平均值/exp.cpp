class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> avg(nums.size(), -1);
        if (2 * k + 1 > nums.size())
            return avg;
        int left = 0, right = 2 * k;
        long long sum = 0;
        for (int i = left;i < right + 1;i++) {
            sum += nums[i];
        }
        while (right < nums.size()) {
            int mid = (left + right) / 2;
            avg[mid] = sum / (2 * k + 1);
            left++;
            right++;
            if (right == nums.size()) 
                break;
            sum = sum - nums[left - 1] + nums[right];
        }
        return avg;
    }
};
