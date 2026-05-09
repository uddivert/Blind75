class Solution {
    int ROWS;
    int COLS;

   public:
    bool exist(vector<vector<char>>& board, string word) {
        ROWS = board.size();
        COLS = board[0].size();
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (dfs(board, word, r, c, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, const string& word, int r, int c, int index) {
        if (index == word.size()) {
            return true;
        }
        if (r < 0 || c < 0 || r > ROWS - 1 || c > COLS - 1 || board[r][c] != word[index]) {
            return false;
        }
        char ch = board[r][c];
        board[r][c] = '0';

        bool val = dfs(board, word, r + 1, c, index + 1) || dfs(board, word, r - 1, c, index + 1) ||
                   dfs(board, word, r, c + 1, index + 1) || dfs(board, word, r, c - 1, index + 1);
        board[r][c] = ch; 
        return val;
    }
};
