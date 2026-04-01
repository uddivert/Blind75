class Solution {
public:
    // if num > current_subarray sum. start new subarray from sum
    // else add it to the subarray
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int max = numeric_limits<int>::min();
        for (int i : nums)
        {
            sum = std::max(sum + i, i);
            max = std::max(sum, max);
        }
        return max;
    }
};
