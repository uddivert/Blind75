class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int size = 0;
        unordered_set <int> set;

        for (int i : nums)
        {
            set.insert(i);
        }
        for (int i : set)
        {
            int count = 0;
            int val = i;
            if(!set.count(val -1))
            {
                while (set.count(val))
                {
                    count ++;
                    size = max(count, size);
                    val ++;
                }
            }
        }
        return size; 
    }
};
