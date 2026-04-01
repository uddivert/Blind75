class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int profit = 0; 
        int lowest = prices[0];

        for (int i = 0; i < prices.size(); i ++)
        {
            lowest = min( lowest, prices[i]);
            profit = max(profit, prices[i] - lowest);
        }
        return profit;
    }
};
