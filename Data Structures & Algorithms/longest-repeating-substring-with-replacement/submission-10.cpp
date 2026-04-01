class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> map;
        int frequency = 0;
        int right = 0;
        int left = 0;
        int length = 0;

        while (right < s.size())
        {
            map[s[right]] +=1;
            frequency = max(map[s[right]], frequency);

            while (left < right && right - left + 1 - frequency > k)
            {
                map[s[left]] --;
                left ++;
            }
            length = max(right - left + 1, length); 
            right ++;
        }
        return length;
    }
};
