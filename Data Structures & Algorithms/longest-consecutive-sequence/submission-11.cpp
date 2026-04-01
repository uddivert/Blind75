class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int max = 0;

        std::unordered_set <int> set (nums.begin(), nums.end());

        for (int num : set)
        {
            int current = num;
            if (set.count(current -1) == 0)
            {
                int current_max = 0;
                while (set.count(current + 1))
                {
                    current_max ++;
                    current ++;
                }
                max = std::max(max, current_max + 1);
            }
        }
        return max;
    }
};
