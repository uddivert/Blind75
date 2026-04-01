class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = 0;
        int left = 0;
        int right = 0;
        unordered_set <char> found;

        while (right < s.size())
        {
            while (found.count(s[right]))
            {
                found.erase(s[left]);
                left ++;
            }
            found.insert(s[right]);
            size = max (size, right - left +1);
            right ++;
        }
        return size;
    }
};
