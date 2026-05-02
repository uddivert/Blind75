class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> frequency;
        for (int n : nums)
        {
            frequency[n] ++;
        }
        vector<pair<int, int>> sorted;
        for (const auto & pair : frequency)
        {
            sorted.push_back({pair.second, pair.first});
        }
        sort(sorted.rbegin(), sorted.rend());
        vector <int> result;
        for (int i = 0; i < k; i ++)
        {
            result.push_back(sorted[i].second);
        }
        return result;
    }
};
