class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int left = 0;
        int size = 0;
        for (int right = 0; right < s.size(); right ++)
        {
            while (set.contains(s[right]))
            {
                set.erase(s[left]);
                left ++;
            }
            set.insert(s[right]);
            size = max(right - left +1 , size);
        }
        return size;
    }
};
