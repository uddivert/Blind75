class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result;
        for (int i = 0; i <= n; i ++)
        {
            int count = 0;
            int x = i;
            while (x != 0)
            {
                count += (x & 1) ? 1 : 0;
                x >>= 1;
            }
            result.push_back(count);
        }
        return result;
    }
};
