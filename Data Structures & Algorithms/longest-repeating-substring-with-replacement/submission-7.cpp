class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, length = 0, freq = 0;
        unordered_map <char, int> seen;

        for (int right = 0; right < s.size(); right++)
        {
           seen[s[right]] +=1;
           freq = max(freq, seen[s[right]]);
           while (right - left + 1 - freq > k)
           {
            seen[s[left]] -=1;
            left ++;
           } 
           length = max(right - left +1, length);
        } 
        return length;
    }
};
