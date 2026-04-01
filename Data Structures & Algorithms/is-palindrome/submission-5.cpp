#include <cctype>
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0; 
        int right = s.size() -1;

        while (left < right)
        {
            while (!std::isalnum(static_cast<int>(s[left])))
            {
                left ++;
            }
            while (!std::isalnum(static_cast<int>(s[right])))
            {
                right --;
            }
            if (left < right &&
                 std::tolower(static_cast<int>(s[right])) != 
                 std::tolower(static_cast<int>(s[left])))
            {
                return false;
            }
            left ++;
            right --;
        }
        return true;
    }
};
