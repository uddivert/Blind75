#include <cctype>
class Solution {
public:
    bool isPalindrome(string s) {
        string new_string;
        for (char ch : s)
        {
            if (ch == ' ' || !std::isalnum(static_cast<int>(ch)))
            {
                continue;
            }
            else
            {
                new_string += std::tolower(static_cast<int>(ch));
            }
        }
        string reverse (new_string.rbegin(), new_string.rend());
        return reverse == new_string;
    }
};
