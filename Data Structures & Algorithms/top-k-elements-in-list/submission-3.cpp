class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> map;
        for (int i : nums)
        {
            map[i] +=1;
        }
        vector<pair<int, int>> vec;
        for (const auto &pair : map)
        {
           vec.push_back(pair); 
        }
        sort(vec.begin(), vec.end(), [] (const auto &pair1, const auto &pair2)
        {
            return pair1.second > pair2.second;
        });
        vector<int> result;
        for (int i = 0; i < k; i ++)
        {
            result.push_back(vec[i].first);
        }
        return result;
    }
};
