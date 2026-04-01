class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> prefix(nums.size());
        int prefix_value = 1;
        for (int i = 0; i < nums.size(); i ++)
        {
            prefix[i] = prefix_value;
            prefix_value *= nums[i];
        }

        vector<int> suffix(nums.size());
        int suffix_value = 1;
        for (int i = nums.size() -1; i > -1; i --)
        {
            suffix[i] = suffix_value;
            suffix_value *= nums[i];
        }

        vector<int> result(nums.size());
        for (int i = nums.size() -1; i > -1; i --)
        {
            result[i] = prefix[i] * suffix[i];
        }
        return result;
    }
};
