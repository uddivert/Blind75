class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int result = 0;
        unordered_set<char> seen;
        while (right < s.size()) 
        {
            while (seen.contains(s[right])) 
            {
                seen.erase(s[left]);
                left ++;
            }
            seen.insert(s[right]);
            result = max(result, right - left + 1);
            right ++;
        }
        return result;
    }
};
