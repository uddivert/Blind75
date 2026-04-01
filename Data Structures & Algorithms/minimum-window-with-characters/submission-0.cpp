#include <limits>

class Solution {
public:
    string minWindow(string s, string t) {

        // frequency map of t
        unordered_map <char, int> t_frequency;
        
        // put t into a frequency map
        for (char c : t)
        {
            t_frequency[c] +=1;
        }

        pair <int, int> result;
        int result_length = std::numeric_limits<int>::max();

        // iterate through s
        for (int i = 0; i < s.size(); i ++)
        {
            unordered_map <char,int> s_frequency;
            
            for (int j = i; j < s.size(); j ++)
            {
                s_frequency[s[j]] +=1;

                // flag is true if t_frequency == s_frequency
                bool flag = true;
                
                for (const auto &[t_char, t_count] : t_frequency)
                {
                    if (s_frequency[t_char] < t_count)
                    {
                        flag = false;
                        break;
                    }
                }

                int length = j - i + 1;

                if (flag && length < result_length)
                {
                    result_length = length;
                    result = {i , j};
                }
            }
        }
        return result_length == std::numeric_limits<int>::max() ? "" : s.substr(result.first, result_length); 
    }
};
