class Solution {
public:
    int characterReplacement(string s, int k) {
        // if (r - l + 1) - maxf <= k
        // {
        //  r ++
        // }
        // else { l ++}

        int result = 0, maxf = 0;
        int left = 0, right = 0;
        
        unordered_map <char, int> count;
        
        while (right < s.size())
        {
            count[s[right]] +=1;
            maxf = max(maxf, count[s[right]]);
            
            while ((right - left + 1 - maxf) > k)
            {
                count[s[left]] --;
                left ++;
            }
            result = max(right - left + 1, result);
            right ++;
        }
        return result;
    }
};
