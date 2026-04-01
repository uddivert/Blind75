#include <array>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::map <string, vector<string> > string_map{}; 
        for (string s : strs)
        {
            // find frequency
            std::array <int, 26> frequency = {};
            for (char ch : s)
            {
                frequency[ch - 'a'] ++;
            }

            string key;
            for (int f : frequency)
            {
                key += to_string(f) + "$";
            }
            string_map[key].push_back(s);
        }
        vector<vector<string>> result ={};
        for (auto & p: string_map)
        {
            auto group = p.second;
            result.push_back(std::move(group));
        }
        return result;
    }
};
