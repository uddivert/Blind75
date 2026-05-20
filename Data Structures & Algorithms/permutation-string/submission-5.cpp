class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        int window_size = s1.size();
        vector<int> s1_freq(26, 0);
        vector<int> window_freq(26, 0);
        if (s1.size() > s2.size()) {
            return false;
        }
        for (int i = 0; i < window_size; i++) {
            window_freq[s2[i] - 'a']++;
            s1_freq[s1[i] - 'a']++;
        }
        if (s1_freq == window_freq) {
            return true;
        }
        for (int i = window_size; i < s2.size(); i++) {
            window_freq[s2[i] - 'a']++;
            window_freq[s2[i - window_size] - 'a']--;
            if (s1_freq == window_freq) {
                return true;
            }
        }
        return false;
    }
};
