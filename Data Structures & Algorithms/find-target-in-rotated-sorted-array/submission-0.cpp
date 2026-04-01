class Solution {
public:
    int search(vector<int>& nums, int target) {
       int right = nums.size() -1;
       int left = 0;

       while (left < right)
       {
        int middle = left + (right - left) / 2;
        if (nums[middle] > nums[right])
        {
            left = middle + 1;
        }
        else 
        {
            right = middle;
        }
       }

       int pivot = left;
       left = 0;
       right = nums.size() -1;

       if (target >= nums[pivot] && target <= nums[right]) 
       {
        left = pivot;
       }
       else
       {
        right = pivot -1; 
       }

       while (left <= right)
       {
        int middle = left + (right - left) / 2;
        if (nums[middle] == target)
        {
            return middle;
        }
        else if (nums[middle] < target) 
        {
            left = middle + 1;
        }
        else 
        {
            right = middle -1;
        }
       }
       return -1;

    }
};
