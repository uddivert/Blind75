class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> freq;
        for (char ch : s1)
        {
            freq[ch] += 1;
        }
        for (int left = 0; left < s2.length(); left ++)
        {
            if (freq.contains(s2[left]))
            {
                unordered_map<char, int> freq1;
                if (left + s1.size() <= s2.size())
                for (char ch : s2.substr(left, s1.size()))
                {
                    freq1[ch] += 1;
                }
                if (freq == freq1)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
