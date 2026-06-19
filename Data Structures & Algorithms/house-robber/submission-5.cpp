class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> cache(nums.size(), -1);
        dfs(nums, cache, 0);
        return cache[0];
    }
    int dfs(vector<int>& nums, vector<int>& cache, int index)
    {
        if (index >= nums.size())
        {
            return 0;
        }
        if (cache[index] != -1)
        {
            return cache[index];
        }
        return cache[index] = max(dfs(nums, cache, index + 1), nums[index] + dfs(nums, cache, index + 2));
    }
};
