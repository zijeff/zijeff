class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        int k = -1;
        while (left != right) {
            if (nums[left] + nums[right] > 0)
                right--;
            else if (nums[left] + nums[right] < 0)
                left++;
            else {
                k = nums[right];
                break;
            }
        }
        return k;
    }
};
