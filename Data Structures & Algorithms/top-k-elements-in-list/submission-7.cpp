class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> temp;
        for (int i : nums)
        {
            temp[i] ++;
        }
        vector<pair<int,int>> v;
        for (const auto& [val, count] : temp)
        {
            v.push_back({count,val});
        }
        sort(v.rbegin(), v.rend());
        vector<int> result;
        for (int i = 0; i < k; i ++)
        {
            result.push_back(v[i].second);
        }
        return result;
    }
};
