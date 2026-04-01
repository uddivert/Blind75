class Solution {
public:
    int characterReplacement(string s, int k) {

        unordered_map <char, int> map;
        int left = 0;
        int freq = 0;
        int length = 0;
        for (int right = 0; right < s.size(); right ++)
        {
            map[s[right]] +=1;
            freq = max(map[s[right]], freq);
            while (left < right && right - left + 1 - freq > k)
            {
                map[s[left]] --;
                left ++;
            }
            length = max(length, right - left + 1);
        }
        return length;
        
    }
};
