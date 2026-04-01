class Solution {
public:
    int findMin(vector<int> &nums) {
       int result = nums[0];
       int left = 0;
       int right = nums.size() -1;

       while (left <= right)
       {
        if (nums[left] < nums[right])
        {
            result = min(nums[left], result);
            break;
        }
        int middle = left + (right - left) / 2;
        result = min(nums[middle], result);

        if (nums[middle] >= nums[left])
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
