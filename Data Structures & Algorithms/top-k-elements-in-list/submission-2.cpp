class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       // make map <number, frequency> map
       // array[number,frequency]
       // std::sort(array, new compare function);
       // for ( i < k) {result.push_back(array[i])}
       // return result

       unordered_map<int, int> map;

       for (int i = 0; i < nums.size(); i ++)
       {
            map[nums[i]] +=1;
       }

       vector<pair<int, int>> vec;
       for (auto it = map.begin(); it != map.end(); ++it)
       {
            vec.push_back({it->first, it->second});
       }
       std::sort(vec.begin(), vec.end(),[&](auto const & a, auto const & b)
       {
            return a.second > b.second;
       });

        vector <int> result;
       for (int i = 0; i < k; i ++)
       {
            result.push_back(vec[i].first);
       }
       return result;
    }
};
