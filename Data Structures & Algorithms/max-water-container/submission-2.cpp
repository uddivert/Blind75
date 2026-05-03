class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() -1;
        int area = 0;

        while (l < r)
        {
            int height = min(heights[l], heights[r]); 
            int width = r - l;
            area = max(area, height * width);
            if (heights[l] > heights[r])
            {
                r --;
            }
            else
            {
                l ++;
            }
        }
        return area;
    }
};
