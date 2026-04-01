#include <array>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // find frequnecy of each word
        // map[frequency].push_back(word)
        // for (const auto & pair : map)
        // {result.push_back(pair->second)}

        unordered_map <string, vector<string>> my_map;
        for (string s : strs)
        {
            array<int,26> frequency{};
            for (char ch : s)
            {
                frequency[ch - 'a'] +=1;
            }
            string hash;
            for (int i : frequency)
            {
                hash += to_string(i) + "$";
            }
            my_map[hash].push_back(s);
        }
        vector<vector<string>> result;
        for (const auto & pair : my_map)
        {
            result.push_back(std::move(pair.second));
        } 
        return result;
    }
};
