class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](const vector<int>& point1, const vector<int>& point2)
        {
            return point1[0] * point1[0] + point1[1] * point1[1] >
                    point2[0] * point2[0] + point2[1] * point2[1];
        };
        std::priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> min_heap(cmp);
        for (const auto & arr : points)
        {
            min_heap.push(arr);
        }

        vector<vector<int>> result;
        while (k >0)
        {
            result.push_back(min_heap.top());
            min_heap.pop();
            k --;
        }
        return result;
    }
};
