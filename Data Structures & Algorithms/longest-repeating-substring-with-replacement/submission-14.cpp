class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int greatest = 0;
        int size = 0;
        unordered_map<char, int> map;
        for (int right = 0; right < s.size(); right ++)
        {
            map[s[right]] +=1;
            greatest = max(greatest, map[s[right]]);
            while (right - left + 1 - greatest > k)
            {
                map[s[left]] -= 1;
                left ++;
            }
            size = max(size, right - left + 1);
        }
        return size;
    }
};
