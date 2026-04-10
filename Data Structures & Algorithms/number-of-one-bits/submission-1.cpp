class Solution {
public:
    int hammingWeight(uint32_t n) {
        int counter = 0; 
        while (n != 0)
        {
            counter += (n & 1) ? 1 : 0; 
            n >>= 1; 
        }
        return counter;
    }
};
