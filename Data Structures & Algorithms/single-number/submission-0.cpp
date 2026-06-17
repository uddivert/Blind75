class Solution {
public:
    int singleNumber(vector<int>& nums) {
        uint32_t temp = 0;
        for (int i : nums)
        {
            temp ^= i;
        }
        return temp;
    }
};
