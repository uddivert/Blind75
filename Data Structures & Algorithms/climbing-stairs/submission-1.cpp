class Solution {
public:
    int climbStairs(int n) {
        vector<int> cache(n, -1);
        return dfs(cache, 0, n);    
    }
    int dfs(vector<int>& cache, int step ,int n)
    {
        if (step > n)
        {
            return 0;
        }
        if (step == n)
        {
            return 1;
        }
        if (cache[step] != -1)
        {
            return cache[step];
        }
        return cache[step] = dfs(cache, step + 1, n) + dfs(cache, step + 2, n);

    }
};
