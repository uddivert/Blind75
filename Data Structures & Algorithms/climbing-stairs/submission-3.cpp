class Solution {
public:
    int climbStairs(int n) {
        vector<int> cache(n + 1, -1);
        return dp(0, n, cache);
    }
    int dp(int index, int target, vector<int>& cache)
    {
        if (index > target)
        {
            return 0;
        }
        if (index == target)
        {
            return 1;
        }
        if (cache[index] != -1)
        {
            return cache[index];
        }
        return cache[index] = dp(index + 1, target, cache) + dp(index + 2, target, cache);
    }
};
