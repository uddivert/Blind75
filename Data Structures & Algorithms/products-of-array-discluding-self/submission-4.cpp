class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> prefix(size, 1);
        int product = 1;
        for (int i = 1; i < size; i ++)
        {
            product = nums[i -1] * product;
            prefix[i] = product;
        }
        product = 1;
        for (int i = size -2; i >=0 ; i --)
        {
            product = nums[i +1] * product;
            prefix[i] *= product;
        }
        return prefix;
    }
};
