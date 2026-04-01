class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        // put in map
        // check if previous exists
        unordered_set <int> set(nums.begin(), nums.end());
        int max = 0;

        for (const auto& i : set)
        {
            if (set.contains(i -1))
            {
                continue;
            }
            else 
            {
                int count = 1;
                int val = i;
                while ( set.contains( val + 1))
                {
                    count ++; 
                    val ++; 
                }
                max = std::max(max, count);
            }
        }
        return max;
    }
};
