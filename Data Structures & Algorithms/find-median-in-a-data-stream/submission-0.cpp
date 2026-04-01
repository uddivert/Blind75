class MedianFinder {
    priority_queue<int, vector<int>, std::greater<int>> large_heap;
    priority_queue<int, vector<int> , std::less<int>> small_heap;    
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        small_heap.push(num);
        if (!large_heap.empty() && small_heap.top() > large_heap.top())
        {
            large_heap.push(small_heap.top());
            small_heap.pop();
        }
        if (small_heap.size() > large_heap.size() + 1)
        {
            large_heap.push(small_heap.top());
            small_heap.pop();
        }
        if (large_heap.size() >  small_heap.size() + 1)
        {
            small_heap.push(large_heap.top());
            large_heap.pop();
        }
        
    }
    
    double findMedian() {
        if (large_heap.size() > small_heap.size())
        {
            return large_heap.top();
        }
        if (large_heap.size() < small_heap.size())
        {
            return small_heap.top();
        }
        return ((large_heap.top() + small_heap.top()) / 2.0);
        
    }
};
