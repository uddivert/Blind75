class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size() -1;
        int result = nums[0];
        while (left <= right)
        {
            if (nums[left] < nums[right])
            {
                return min(result, nums[left]);
            }
            int middle = (left + right) / 2;
            result = min(nums[middle], result);
            if (nums[left] <= nums[middle])
            {
                left = middle + 1;
            }
            else
            {
                right = middle -1;
            }
        }
        return result;
    }
};
