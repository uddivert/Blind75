class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> map;
       for (int i = 0; i < nums.size(); i ++)
       {
            int search = target - nums[i];
            if (map.count(search))
            {
                return {map[search], i};
            }
            map[nums[i]] = i;
       } 
       return {};
    }
};
