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

        for (int right = 0; right < s.size(); right ++)
        {
            // add character to s_map
            s_map[s[right]] ++; 

            bool values_found = true;
            for (const auto &[t_char, t_count] : t_map)
            {
                if (s_map[t_char] < t_count) 
                {
                    values_found = false;
                    break;
                }
            }
            while (values_found)
            {
                if (right - left + 1 < length)
                {
                    index = {left, right};
                    length = right - left + 1;
                }
                s_map[s[left]] --;
                left ++;

                for (const auto &[t_char, t_count] : t_map)
                {
                    if (s_map[t_char] < t_count) 
                    {
                        values_found = false;
                        break;
                    }
                }
            }
        } 
       return length == std::numeric_limits<int>::max() ? "" :
                        s.substr(index.first, length); 
    }
};
