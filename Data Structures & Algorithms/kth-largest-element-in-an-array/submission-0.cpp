class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> queue;
        for (int i : nums)
        {
            queue.push(i);
            if (queue.size() > k)
            {
                queue.pop();
            }
        }
        return queue.top();
    }
};
