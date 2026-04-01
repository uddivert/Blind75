class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int left = 0;
        int result = 0;
        for (int right = 0; right < s.size(); right++)
        {
            while (seen.contains(s[right]))
            {
                seen.erase(s[left]);
                left ++;
            }
            seen.insert(s[right]);
            result = max(result, static_cast<int>(seen.size()));
        }
        return result;
    }
};
