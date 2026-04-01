class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int smallest = prices[0];
        int profit = 0;

        for (int i = 0; i < prices.size(); i ++)
        {
            if (prices[i] < smallest)
            {
                smallest = prices[i];
            }
            int current_profit = prices[i] - smallest;
            if (current_profit > profit)
            {
                profit = current_profit;
            }
        }
        return profit;
    }
};
