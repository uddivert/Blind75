class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set <char> found;
        int left = 0;
        int result = 0;

        for (int right = 0; right < s.size(); right ++)
        {
            while (left < right && found.count(s[right])) 
            {
                found.erase(s[left]);
                left ++;
            }
            found.insert(s[right]);
            result = max(right - left + 1, result);
        }
        return result;
    }
};
