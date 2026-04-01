#include <array>
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        std::array<int, 26> s_array{};
        std::array<int, 26>t_array{};

        for (char ch : s)
        {
            s_array[ch - 'a'] ++;
        }
        for (char ch: t)
        {
            t_array[ch - 'a'] ++;
        }
        return (s_array == t_array);
    }
};
