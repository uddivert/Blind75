class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> set(nums.begin(), nums.end());
        int max_length = 0;

        for (int i = 0; i < nums.size(); i ++)
        {
            if (!set.count(nums[i] -1))
            {
                int length = 0;
                
                while (set.count(nums[i] + length))
                {
                    max_length = max(length + 1, max_length);
                    length ++;
                }
            }
        }
       return max_length; 
    }
};
