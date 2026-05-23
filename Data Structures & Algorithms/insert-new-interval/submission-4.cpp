class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (newInterval.empty())
        {
            return intervals;
        }
        int left = 0;
        int right = intervals.size() -1;
        int target = newInterval[0];
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (intervals[mid][0] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid -1;
            }
        }
        intervals.insert(intervals.begin() + left, newInterval);
        vector<vector<int>> res;
        for (auto & i : intervals)
        {
            if (res.empty() || res.back()[1] < i[0])
            {
                res.push_back(i);
            }
            else
            {
                res.back()[1] = max(i[1], res.back()[1]);
            }
        }
        return res;
    }
};
