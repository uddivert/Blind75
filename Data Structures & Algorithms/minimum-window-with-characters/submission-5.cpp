#include <limits>
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map <char, int> s_map;
        unordered_map<char, int> t_map;
        int left  = 0;
        int length = std::numeric_limits<int>::max();
        pair<int, int> index;

        // put t values into a map
        for (char ch : t)
        {
            t_map[ch] ++;
        }

        int have = 0;
        int need = t_map.size();
        for (int right = 0; right < s.size(); right ++)
        {
            // add character to s_map
            s_map[s[right]] ++; 

            if (t_map.count(s[right]) && s_map[s[right]] == t_map[s[right]])
            {
                have ++;
            }
            while (have == need)
            {
                if (right - left + 1 < length)
                {
                    index = {left, right};
                    length = right - left + 1;
                }
                s_map[s[left]] --;
                if (t_map.count(s[left]) && s_map[s[left]] < t_map[s[left]])
                {
                    have --;
                }
                left ++;
            }
        } 
       return length == std::numeric_limits<int>::max() ? "" :
                        s.substr(index.first, length); 
    }
};
