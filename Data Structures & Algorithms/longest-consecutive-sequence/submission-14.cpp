class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> vals;
        for (int i : nums)
        {
            vals.insert(i);
        }
        int count = 0;
        for (int i = 0; i < nums.size(); i ++)
        {
            if (!vals.contains(nums[i] -1))
            {
                int j = nums[i] + 1;
                int temp = 1;
                while (vals.contains(j))
                {
                    temp ++;
                    j ++;
                }
                count = max(temp, count);
            }
        }
        return count;
    }
};
