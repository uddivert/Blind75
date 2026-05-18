class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> cache(nums.size(), -1);
        int result = 0;
        for (int i = 0; i < nums.size(); i ++)
        {
            result = max(dfs(nums, i, cache), result);
        } 
        return result;
    }
    int dfs(vector<int>& nums, int index, vector<int>& cache)
    {
        if (index >= nums.size())
        {
            return 0;
        }
        if (cache[index] != -1)
        {
            return cache[index];
        }
        int best = 1;
        for (int j = index + 1; j < nums.size(); j ++)
        {
            if (nums[index] < nums[j])
            {
                best = max(best, 1+ dfs(nums, j, cache));
            }
        }
        return cache[index] = best;
    }
};
