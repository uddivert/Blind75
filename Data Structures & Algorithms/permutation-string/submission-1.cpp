class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        int window_size = s1.size();
        vector<int> s1_freq(26, 0);
        for (char ch : s1) {
            s1_freq[ch - 'a']++;
        }
        for (int i = 0; i + window_size <= s2.size(); i++) {
            string comparison = s2.substr(i, window_size);
            vector<int> comparison_freq(26, 0);

            for (char ch : comparison) {
                comparison_freq[ch - 'a']++;
            }
            bool flag = true;
            for (int i = 0; i < s1_freq.size(); i ++)
            {
                flag = s1_freq[i] == comparison_freq[i];
                if (!flag)
                {
                    break;
                }
            }
            if (flag)
            {
                return true;
            }
        }
        return false;
    }
};
