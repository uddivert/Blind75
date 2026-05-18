class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = nums[0];
        int my_max = 1;
        int my_min = 1;
        for (int i : nums)
        {
            int product = my_max * i;
            my_max = max(max(product, my_min * i), i);
            my_min = min(min(product, my_min * i), i);
            result = max(my_max, result);
        }
        return result;
    }
};
