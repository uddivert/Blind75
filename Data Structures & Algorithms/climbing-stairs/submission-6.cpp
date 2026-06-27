class Solution {
public:
    int climbStairs(int n) {
        vector<int> cache(n +1, -1);
        return dp(0, cache);
    }
    int dp(int index, vector<int>& cache)
    {
        if(index >= cache.size())
        {
            return 0;
        }
        if (cache[index] != -1)
        {
            return cache[index];
        }
        if (index == cache.size() -1)
        {
            return 1;
        }
        return cache[index] = dp(index + 1, cache) + dp(index +2, cache);
    }
};
