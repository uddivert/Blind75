class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        return myTwoSum(nums, map, target, 0);
    }
    
    vector<int> myTwoSum(vector<int>& nums, unordered_map<int,int>& map, int target,int i)
    {
        if (i == nums.size())
        {
            return {};
        }
        int val = target - nums[i];
        if (map.contains(val))
        {
            return {map[val], i};
        }
        map[nums[i]] = i;
        return myTwoSum(nums, map, target, i + 1); 
    }
};
