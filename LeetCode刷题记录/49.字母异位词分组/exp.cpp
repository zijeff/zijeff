class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> hashset;
        for (int i = 0; i < strs.size(); i++)
        {
            string key = strs[i];
            sort(key.begin(), key.end());
            hashset[key].push_back(strs[i]);
        }
        vector<vector<string>> result;
        for (auto i = hashset.begin(); i != hashset.end(); i++)
        {
            result.push_back(i->second);
        }
        return result;
    }
};
