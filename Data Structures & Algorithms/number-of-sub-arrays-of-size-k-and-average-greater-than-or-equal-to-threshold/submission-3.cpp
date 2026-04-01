class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {

        int left = 0, num = 0;
        while ((left + k) <= arr.size())
        {
            int average = 0;
            for (int i = 0; i <k; i ++ )
            {
               average += arr[left + i];
            }
            if (average >= threshold * k)
            {
                num += 1;
            }
            left ++;
        }
        return num; 
    }
};