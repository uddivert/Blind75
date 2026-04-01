class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int result = 0;
        for (int i = 0; i < s.size(); i ++)
        {
            unordered_map<char, int> count;
            int maxf = 0;
            for (int j = i; j < s.size(); j ++)
            {
                // add value to map
                count[s[j]] ++;
                maxf = max(maxf, count[s[j]]);

                int window_size = j - i + 1;

                if (window_size - maxf <= k)
                {
                   result = max(result, window_size);
                }
            }
        }
        return result;
    }
};
