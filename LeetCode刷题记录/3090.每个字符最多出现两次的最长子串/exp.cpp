class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> hashset;
        int left = 0, right = 1;
        int res = 2;
        hashset.emplace(s[left], 1);
        if (hashset.find(s[right]) != hashset.end())
            hashset[s[right]]++;
        else
            hashset.emplace(s[right], 1);
        for (int i = right;i < s.length() - 1;i++) {
            if (hashset.find(s[i + 1]) != hashset.end())
                hashset[s[i + 1]]++;
            else
                hashset.emplace(s[i + 1], 1);
            while (hashset[s[i + 1]] > 2) {
                hashset[s[left]]--;
                left++;
            }
            res = max(res, i - left + 2);
        }
        return res;
    }
};
