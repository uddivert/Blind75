class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;   
        for (const auto & s: strs)
        {
            array<int, 26> freq{0};
            for(char c : s)
            {
                freq[c - 'a'] ++;
            }
            string hash;
            for (int i = 0; i < 26; i ++)
            {
                hash += to_string(freq[i]) + 'k';
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
