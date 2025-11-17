class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int res = 0;
        int left = 0;
        int cnt_0 = 0;
        if (nums[0] == 0)
            cnt_0 = 1;
        for (int right = left;right < nums.size() - 1;right++) {
            if (nums[right + 1] == 0)
                cnt_0++;
            while (cnt_0 > 1) {
                if (nums[left] == 0)
                    cnt_0--;
                left++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};
