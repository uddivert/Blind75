#include <string>
#include <vector>

class Solution {
public:

    string encode(vector<string>& strs) {
        string result;
        for (string s : strs)
        {
            int size = s.size();
            result += to_string(size) + "p" +s;
        }
        return result;
    }

    vector<string> decode(string s) {
         int index = 0;
         vector <string> result;
        while (index < s.size())
        {
            string ssize;

            while (s.at(index) != 'p') 
            {
                ssize +=s.at(index);
                index ++;
            }

            string val;
            int size = stoi(ssize);
            index ++;

            while (size > 0)
            {
                val +=s.at(index);
                size --;
                index ++;
            }
            result.push_back(val);
        }
        return result;
    }
};
