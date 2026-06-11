class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> queue;
        for (int i : nums)
        {
            queue.push(i);
        }
        vector<int> sorted;
        while (!queue.empty())
        {
            sorted.push_back(queue.top());
            queue.pop();
        }
        return sorted;
    }
};