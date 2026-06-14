class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int ROWS = board.size();
        int COLS = board[0].size();

        unordered_map<int, unordered_set<int>> r_map;
        unordered_map<int, unordered_set<int>> c_map;
        map<pair<int,int>, unordered_set<int>> square;
        for (int r = 0; r < ROWS; r ++)
        {
            for (int c = 0; c < COLS; c ++)
            {
                if (board[r][c] == '.')
                {
                    continue;
                }
                int val = board[r][c] - '0';
                pair<int, int> p({r / 3, c / 3});
                if (r_map[r].contains(val) || c_map[c].contains(val) || square[p].contains(val) )
                {
                    return false;
                }
                r_map[r].insert(val);
                c_map[c].insert(val);
                square[p].insert(val);
            }
        }
        return true;
    }
};
