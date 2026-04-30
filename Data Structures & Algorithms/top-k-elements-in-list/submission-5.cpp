class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq; // number, frequency
        for (int i : nums)
        {
            freq[i] ++;
        }
        vector<pair<int, int>> ordered(freq.size());
        for (const auto & pair : freq)
        {
            ordered.push_back({pair.second, pair.first});
        }
        sort(ordered.rbegin(), ordered.rend());
        vector<int> result(k);
        for (int i = 0; i < k; i ++)
        {
            result[i] = ordered[i].second;
        }
        return result;
    }
};
