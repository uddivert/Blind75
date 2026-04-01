#include <array>
class Solution {
public:
    bool isAnagram(string s, string t) {
        std::array<int, 26> freq1 {};
        std::array<int, 26> freq2{};

        for (char ch : s)
        {
            freq1[ch - 'a'] +=1;
        }
        for (char ch : t)
        {
            freq2[ch - 'a'] +=1;
        }
        return freq1 == freq2;
    }
};
