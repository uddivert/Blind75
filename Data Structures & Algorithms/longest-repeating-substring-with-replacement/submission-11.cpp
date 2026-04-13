class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int maxf = 0;
        int result = 0;
        unordered_map<char, int> freq;
        for (int right = 0; right < s.size(); right ++)
        {
            freq[s[right]] +=1;
            maxf = std::max(freq[s[right]], maxf);

            while ((right - left + 1 ) - maxf > k)
            {
                freq[s[left]] --;
                left ++;
            }
            result  = std::max(result, right - left + 1 );
        }
        return result;
    }
};
