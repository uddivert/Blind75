class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int left = 0;
        int size = 0;
        for (int right = 0; right < s.size(); right ++)
        {
            freq[s[right]] ++;
            int max_char = 0;
            for (const auto &[character, count]: freq)
            {
                max_char = max(max_char, count);
            }
            if (right - left + 1 - max_char > k)
            {
                freq[s[left]] --;
                left ++;
            }
            size = max(right - left + 1, size);
        }
        return size;
    }
};
