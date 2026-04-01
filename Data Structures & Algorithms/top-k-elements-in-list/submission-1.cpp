class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map <int, int> frequency_map;
        for (int i = 0; i < nums.size(); ++i)
        {
            int value = nums[i];
            frequency_map[value] += 1;
        }

        vector <pair<int,int>> sorted;
        for(const auto &duo : frequency_map)
        {
            sorted.push_back({duo.first, duo.second});
        }

        std::sort(sorted.begin(), sorted.end(), [&](const auto &a, const auto &b){
            return a.second > b.second;
        });

        vector <int> result;

        for (int i = 0; i < k; i ++)
        {
            result.push_back(sorted[i].first);
        }

        return result;
    }
};
