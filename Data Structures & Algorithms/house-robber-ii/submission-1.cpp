class Solution {
   public:
    int rob(vector<int>& nums) {
        vector<int> cache1(nums.size(), -1);
        vector<int> cache2(nums.size(), -1);
        if (nums.size() == 1)
        {
            return nums[0];
        }
        return max(dfs(cache1, nums, 1, false), dfs(cache2, nums, 0, true));
    }
    int dfs(vector<int>& cache, vector<int>& nums, int index, bool flag) {
        if (index >= nums.size()) {
            return 0;
        }
        if (flag && index == nums.size() - 1) {
            return 0;
        }
        if (!flag && index == 0) {
            return 0;
        }
        if (cache[index] != -1) {
            return cache[index];
        }
        return cache[index] = max(nums[index] + dfs(cache, nums, index + 2, flag),
                                  dfs(cache, nums, index + 1, flag));
    }
};
