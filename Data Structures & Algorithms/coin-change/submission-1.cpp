class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        unordered_map<int, int> cache; // coins, ways 
        if (dfs(coins, cache, amount) == std::numeric_limits<int>::max())
        {
            return -1;
        }
        return cache[amount];
    }
    int dfs(vector<int>& coins, unordered_map<int,int>& cache, int amount)
    {
        if (amount == 0)
        {
            return 0;
        }
        if (cache.count(amount))
        {
            return cache[amount];
        }
        int result = std::numeric_limits<int>::max();
        for (int i : coins)
        {
            if (amount - i >=0)
            {
                int temp = dfs(coins, cache, amount - i );
                if (temp != numeric_limits<int>::max())
                {
                    result = min(result, temp + 1);
                }
            }
        }
        return cache[amount] = result;
    } 

};
