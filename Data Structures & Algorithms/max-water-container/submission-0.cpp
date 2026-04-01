class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() -1;
        int max = 0;

        while (left < right)
        {
            int minimum = min(heights[left], heights[right]);
            int width = right - left;
            int product = width * minimum;
            if (product > max)
            {
                max = product;
            }

            if (heights[left] < heights[right])
            {
                left ++;
            }
            else
            {
                right --;
            }
        }
        return max;
    }
};
