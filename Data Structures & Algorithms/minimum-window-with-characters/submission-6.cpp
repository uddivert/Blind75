#include <limits>
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> t_map;
        for(char ch : t)
        {
            t_map[ch] +=1;
        } 
        
        int left = 0;
        unordered_map<char, int> s_map;
        int size = std::numeric_limits<int>::max();
        pair<int, int> index;
        for (int right = 0; right < s.size(); right ++)
        {
            s_map[s[right]] +=1;
            bool is_valid = true;
            for (auto const &pair : t_map)
            {
                if (t_map[pair.first] > s_map[pair.first])            
                {
                    is_valid = false;
                }
            }
            while (is_valid)
            {
                if (right - left + 1 < size)
                {
                    size = right - left + 1;
                    index = {left, right};
                }
                s_map[s[left]] -= 1;
                left ++;

                for (auto const &pair : t_map)
                {
                    if (t_map[pair.first] > s_map[pair.first])            
                    {
                        is_valid = false;
                    }
                }
            }
        }
        if (size == std::numeric_limits<int>::max())
        {
            return "";
        }
        else 
        {
            return s.substr(index.first, index.second - index.first + 1);
        }
    }
};

