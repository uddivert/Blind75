class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set <int> set;
        return myHasDuplicate(set, nums, 0);
    }
    bool myHasDuplicate(std::set<int>& set, vector<int>& nums, int i)
    {
        if (i == nums.size())
        {
            return false;
        }

        if (set.contains(nums[i]))
        {
            return true;
        }

        set.insert(nums[i]);
        return myHasDuplicate(set, nums, i + 1);
    }
};