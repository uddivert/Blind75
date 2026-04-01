class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int max_count = 0;
        std::unordered_set <char> substring;

        while (right < s.size())
        {
            if (substring.count(s.at(right)) == 0)
            {
                substring.insert(s.at(right));
                max_count = std::max(max_count, right - left + 1); 
                right ++;
            }
            else
            {
                substring.erase(s.at(left));
                left ++;
            }
        }    
        return max_count;
    }
};
