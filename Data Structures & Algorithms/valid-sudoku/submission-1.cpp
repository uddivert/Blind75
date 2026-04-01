#include <array>
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        std::array<unordered_set<char>, 9> rows;
        std::array<unordered_set<char>, 9> cols;
        std::array<unordered_set<char>, 9> sub;

        for (int i = 0; i < board.size(); i ++)
        {
            for (int j = 0; j < board[i].size(); j ++)
            {
                if (board[i][j] == '.')
                {
                    continue;
                }
                if (cols[j].count(board[i][j]))
                {
                    return false;
                }
                cols[j].insert(board[i][j]);

                if (rows[i].count(board[i][j]))
                {
                    return false; 
                }
                rows[i].insert(board[i][j]);

                if (sub[(i / 3) *3  + j / 3].count(board[i][j]))
                {
                    return false;
                }
                sub[(i / 3) *3  + j / 3].insert(board[i][j]);
            }
        } 
        return true;
    }
};
