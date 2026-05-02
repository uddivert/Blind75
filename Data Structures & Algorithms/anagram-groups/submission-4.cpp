class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;

        for (string s : strs)
        {
            array<int, 26> frequency{0};
            for (char c : s)
            {
                frequency[c - 'a'] +=1;
            }
            string hash;
            for (int i = 0; i < frequency.size(); i++)
            {
                hash += to_string(frequency[i]) + ',';
            }
            map[hash].push_back(s);
        }    
        vector<vector<string>> result;
        for (const auto & pair : map)
        {
            result.push_back(pair.second);
        }
        return result;
    }
};
