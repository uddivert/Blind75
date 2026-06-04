class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string val;
        int max_size = INT_MAX;
        for (string s : strs)
        {
            max_size = min(max_size, static_cast<int>(s.size()));
        }

        for (int i = 0; i < max_size; i ++)
        {
            char ch = strs[0][i];
            for (string s : strs)
            {
                if (s[i] != ch)
                {
                    return val;
                }
            }
            val += ch;
        }
        return val;
    }
};