class Solution {
public:
    int climbStairs(int n) {
        vector<int> cache(n, -1);
        return dfs(cache, 0, n);    
    }
    int dfs(vector<int>& cache, int stair, int target)
    {
        if (stair > target)
        {
            return 0;
        }
        if (stair == target)
        {
            return 1;
        }
        if (cache[stair] != -1)
        {
            return cache[stair];
        }
        return cache[stair] = dfs(cache, stair + 2, target) + dfs(cache, stair + 1, target);
    }
};
