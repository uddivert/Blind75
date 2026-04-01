class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        for (int i = 0; i < nums.size(); i ++)
        {
            int value = 1;
            for (int j = 0; j < nums.size(); j ++)
            {
                if (i != j)
                {
                    value *= nums[j];
                }
            }
            result.push_back(value); 
        }
        return result;
    }
};
