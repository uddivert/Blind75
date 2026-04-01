#include <cctype>
class Solution {
public:
    bool isPalindrome(string s) {
        auto it = s.cbegin();
        auto r_it = s.crbegin();
        for(; it != s.cend(); ++it, ++r_it)
        {
            while (!isalnum(*it))
            {
                if (it == s.cend())
                {
                    break;
                }
                ++it;
            }
            while (!isalnum(*r_it))
            {
                if (r_it == s.crend())
                {
                    break;
                }
                ++r_it;
            }

            if (it > s.cend() || r_it > s.crend()) {
                break;
            }
            if (tolower(*it) != tolower(*r_it))
            {
                return false;
            }
        }
        return true;
    }
};
