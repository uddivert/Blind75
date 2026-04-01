class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        vector<unordered_set<int>> row (9);
        vector<unordered_set<int>> col (9);
        vector<unordered_set<int>>cross (9);

        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[i].size(); ++j)
            {
                if (board[i][j] == '.') continue;
                if (row[i].count(board[i][j]) > 0)
                {
                    return false;
                }
                if (col[j].count(board[i][j]) > 0)
                {
                    return false;
                }
                int k = (i / 3) * 3 + (j / 3);
                if (cross[k].count(board[i][j]) > 0)
                {
                    return false;
                }
                row[i].insert(board[i][j]);
                col[j].insert(board[i][j]);
                cross[k].insert(board[i][j]);
            }
        }

        return true;
        
    }
};
