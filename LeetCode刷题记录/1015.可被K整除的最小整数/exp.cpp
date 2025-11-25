class Solution {
  public:
    int smallestRepunitDivByK(int k) {
        unordered_set<int> mod_k;
        int resid = 1 % k, len = 1;
        while (resid != 0) {
            resid = (resid * 10 + 1) % k;
            len++;
            if (mod_k.find(resid) != mod_k.end())
                return -1;
            mod_k.insert(resid);
        }
        return len;
    }
};
