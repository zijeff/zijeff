class Solution
{
public:
    long long maxSum(vector<int>& nums, int m, int k)
    {
        unordered_map<int, int> hashset;
        long long maxsum = 0, sum = 0;
        for (int i = 0;i < k;i++) {
            if (hashset.find(nums[i]) != hashset.end())
                hashset[nums[i]]++;
            else
                hashset.emplace(nums[i], 1);
            sum += nums[i];
        }
        if (hashset.size() >= m && sum > maxsum) 
            maxsum = sum;
        for (int right = k - 1;right < nums.size() - 1;right++) {
            int left = right - (k - 1);
            sum = sum + nums[right + 1] - nums[left];
            if (hashset.find(nums[right + 1]) != hashset.end())
                hashset[nums[right + 1]]++;
            else
                hashset.emplace(nums[right + 1], 1);
            if (hashset[nums[left]] == 1)
                hashset.erase(nums[left]);
            else
                hashset[nums[left]]--;
            if (hashset.size() >= m && sum > maxsum)
                maxsum = sum;
        }
        return maxsum;
    }
};
