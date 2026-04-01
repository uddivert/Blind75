#include <array>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map <string, vector<string>> map;
        for (int i = 0; i < strs.size(); i ++)
        {
            array<int, 26> array{};
            for (char ch : strs[i])
            {
                array[ch - 'a'] +=1;
            }

            string hash;
            for (int i : array)
            {
                hash += to_string(i) + "$";
            }
            map[hash].push_back(strs[i]);
        }
        vector<vector<string>> result;
        for (const auto &pair : map)
        {
            result.push_back(std::move(pair.second));
        }
        return result;
    }
};
