class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> subset;
        dfs(candidates, target, 0, subset, result);
        return result;    
    }
    void dfs(vector<int>& candidates, int target, int index, vector<int>& subset, vector<vector<int>>& result)
    {
        if (target == 0)
        {
            result.push_back(subset);
            return;
        }
        if (index >= candidates.size() || target < 0)
        {
            return;
        }
        subset.push_back(candidates[index]);
        dfs(candidates, target - candidates[index], index + 1, subset, result);
        subset.pop_back();
        while (index < candidates.size() -1 && candidates[index + 1] == candidates[index])
        {
            index ++;
        }
        dfs(candidates, target, index + 1, subset, result);
    }
};
