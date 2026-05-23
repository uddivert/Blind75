class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> map;
        for (string s : strs)
        {
            vector<int> freq(26, 0);
            for (int i = 0; i < s.size(); i ++)
            {
                freq[s[i] - 'a'] ++;
            }
            string key;
            for (int i : freq)
            {
                key += to_string(i) + "$";
            }
            map[key].push_back(s);
        }
        vector<vector<string>> result;
        for(const auto& [key, val] : map)
        {
            result.push_back(val);
        }
        return result;
    }
};
