class Solution {
   public:
    string minWindow(string s, string t) {
        int left = 0;
        unordered_map<char, int> t_freq;
        unordered_map<char, int> window;
        int have = 0;
        pair<int, int> result;
        int size = INT_MAX;
        for (char ch : t) {
            t_freq[ch] += 1;
        }
        int need = t_freq.size();

        for (int right = 0; right < s.size(); right++) {
            window[s[right]]++;
            if (t_freq.count(s[right]) && t_freq[s[right]] == window[s[right]]) {
                have++;
            }
            while (have == need) {
                int temp = right - left + 1;
                if (temp < size) {
                    size = temp;
                    result = {left, right};
                }
                if (t_freq.count(s[left]) && t_freq[s[left]] == window[s[left]]) {
                    have--;
                }
                window[s[left]]--;
                left++;
            }
        }
        return size == INT_MAX ? "" : s.substr(result.first, size);
    }
};
