class Solution {
    map<int, int> cache;
public:
    int coinChange(vector<int>& coins, int amount) {
        int ways = dfs(coins, amount);
        return ways == INT_MAX ? -1 : ways;
    }

    int dfs(vector<int>& coins, int amount)
    {
        if (amount == 0)
        {
            return 0;
        }
        if (cache.contains(amount))
        {
            return cache[amount];
        }
        int res = INT_MAX;

        for (int c : coins)
        {
            if (amount - c >= 0)
            {
                int val = dfs(coins, amount - c);
                if (val != INT_MAX)
                {
                    res = min(res, 1 + val);
                }
            }
        }
        return cache[amount] = res;
    }
};
