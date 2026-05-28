class Solution {
   public:
    int rob(vector<int>& nums) {
        vector<int> cache(nums.size(), -1);
        return dfs(0, cache, nums);
    }
    int dfs(int index, vector<int>& cache, vector<int>& nums) {
        if (index >= nums.size()) {
            return 0;
        }
        if (cache[index] != -1) {
            return cache[index];
        }
        return cache[index] =
                   max(nums[index] + dfs(index + 2, cache, nums), dfs(index + 1, cache, nums));
    }
};
