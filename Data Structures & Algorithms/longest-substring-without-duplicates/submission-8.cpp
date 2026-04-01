class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_set <char> seen;
       int length = 0;
       int left = 0;
       int right = 0;
       
       while (right < s.size())
       {
        while (seen.count(s[right]))
        {
            seen.erase(s[left]);
            left ++;
        }
        seen.insert(s[right]); 
        length = max(length, right - left + 1);
        right ++;
       }
       return length;
    }
};
