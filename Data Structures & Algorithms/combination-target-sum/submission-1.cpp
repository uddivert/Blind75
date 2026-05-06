class Solution {
   public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> list;
        dfs(nums, target, 0, list);
        return result;
    }
    void dfs(vector<int>& nums, int target, int index, vector<int> list) {
        if (index >= nums.size() || target < 0) {
            return;
        }
        if (target == 0) {
            result.push_back(list);
            return;
        }
        list.push_back(nums[index]);
        dfs(nums, target - nums[index], index, list);
        list.pop_back();
        dfs(nums, target, index + 1, list);
    }
};
