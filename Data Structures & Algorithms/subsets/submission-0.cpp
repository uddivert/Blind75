class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        dfs(nums, 0, subset, result);
        return result; 
    }
    void dfs(vector<int>& nums, int index, vector<int>& subset, vector<vector<int>>& result)
    {
        if (index >= nums.size())
        {
            result.push_back(subset);
            return;
        }
        subset.push_back(nums[index]);
        dfs(nums, index + 1, subset, result);
        subset.pop_back();
        dfs(nums, index + 1, subset, result);
    }
};
