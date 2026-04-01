class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() -1; 
        int area = 0;
        while ( left < right )
        {
            area = max((right - left) * min(heights[left], heights[right]), area);

            if (heights[right] > heights[left])
            {
                left ++;
            }
            else
            {
                right --;
            }
        }
        return area;
    }
};
