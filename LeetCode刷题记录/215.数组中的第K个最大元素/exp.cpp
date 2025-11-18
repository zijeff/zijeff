class Solution {
public:
    int divide(vector<int>& nums, int left, int right) {
        int i = left + rand() % (right - left + 1);
        int pivot = nums[i];
        swap(nums[i], nums[left]);
        i = left + 1;
        int j = right;
        while (true) {
            while (i <= j && nums[i] < pivot) i++;
            while (i <= j && nums[j] > pivot) j--;
            if (i >= j) break;
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
        swap(nums[left], nums[j]);
        return j;
    }
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(NULL));
        int n = nums.size();
        int target_index = n - k;
        int left = 0, right = n - 1;
        while (true) {
            int i = divide(nums, left, right);
            if (i == target_index) return nums[i];
            if (i > target_index) right = i - 1;
            else left = i + 1;
        }
    }
};
