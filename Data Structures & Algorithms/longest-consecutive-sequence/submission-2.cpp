class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
        {
            return 0;
        }

       std::set <int> sorted;

       for (int i : nums)
       {
        sorted.insert(i);
       }

       int longest = 1;
       int current_longest = 1;

       auto last = sorted.begin();
       for (auto it = std::next(last); it !=sorted.end(); ++ it)
       {
        if (*it - *last == 1)
        {
            current_longest +=1;
        }
        else
        {
            current_longest = 1;
        }

        if (current_longest > longest)
        {
            longest = current_longest;
        }
       last = it;
       }
       return longest;
    }
};
