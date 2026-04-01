#include <algorithm>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i ++)
        {
            unordered_set <int> found;
            for (int j = i + 1; j < nums.size(); j ++)
            {
                while (i + 1 < nums.size() && nums[i] == nums[i+1])
                {
                    i++;
                }
                int target = -(nums[i] + nums[j]);
                if (found.count(target))
                {
                    while (j + 1 < nums.size() && nums[j] == nums[j+1])
                    {
                        j++;
                    }
                   result.push_back({nums[i], target, nums[j]});
                }
                found.insert(nums[j]);
            }
        }
        return result; 
    }
};
