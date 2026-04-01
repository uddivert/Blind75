class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int left = 0;
        unordered_set <int> seen;
        for (int right = 0; right < nums.size(); right ++)
        {
            while (right - left > k) 
            {
                seen.erase(nums[left]);
                left ++;
            }
            if (seen.count(nums[right]))
            {
                return true;
            }
            seen.insert(nums[right]);
        } 
        return false;
    }
};