class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::set <int> map;

        for (int i : nums) 
        {
            if (map.count(i))
            {
                return true;
            }
            map.insert(i);
        }
        return false;
    }
};