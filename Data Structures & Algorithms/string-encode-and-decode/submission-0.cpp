class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        for ( auto s: strs)
        {
            encoded += to_string(s.length()) + "#" + s;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector <string> list = {};
        for (auto it = s.cbegin(); it != s.cend();)
        {
            // parse number before #
            string length_str;
            while (*it != '#')
            {
                length_str += *it;
                ++it;
            }
            int length = std::stoi(length_str);

            // skip #
            ++ it;

            // add to string
            string str;
            while (length !=0)
            {
                str += *it;
                ++it;
                --length;
            }
            list.push_back(std::move(str));
        }
        return list;
    }
};
