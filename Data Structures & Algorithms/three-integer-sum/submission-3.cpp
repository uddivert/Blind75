#include <algorithm>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end()); 
        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); i ++)
        {
            if( i > 0 && nums[i] == nums[i -1 ]) continue;

            int left = i + 1;
            int right = nums.size() -1;
            int target = nums[i] * -1;
            while (left < right )
            {
                if (nums[left] + nums[right] > target) 
                {
                    right --;  
                }
                
                else if (nums[left] + nums[right] < target) 
                {
                    left ++; 
                }
                else if (nums[left] + nums[right] == target)
                {
                    result.push_back({nums[left], nums[i], nums[right]});
                    while (left < right && nums[left] == nums[left+1]) left++;
                    while (left < right && nums[right] == nums[right-1]) right--;
                    left ++; 
                    right --;
                }
            }
        }
        return result;
    }
};
