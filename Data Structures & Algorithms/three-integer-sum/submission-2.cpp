#include <algorithm>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for (int i = 0; i < nums.size(); i ++)
        {
            std::unordered_set <int> seen;
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i + 1; j < nums.size(); j ++)
            {
                int target = -1 *(nums[i] + nums[j]);
                if (seen.count(target))
                {
                    while (j + 1 < nums.size() && nums[j] == nums[j+1])
                    {
                        j++;
                    }
                    result.push_back({nums[i], nums[j],target});
                }
                seen.insert(nums[j]);
            }
        }
        return result;
    }
};
