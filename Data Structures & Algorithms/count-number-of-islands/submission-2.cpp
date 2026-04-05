class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int islands = 0;
        for (int r = 0; r < ROWS; r ++)
        {
            for (int c = 0; c < COLS; c ++)
            {
                if (grid[r][c] == '1')
                {
                    dfs(grid, r, c);
                    islands ++;
                }
            }
        } 
        return islands;
    }
    void dfs(vector<vector<char>>& grid, int r, int c)
    {
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == '0')
        {
            return;
        }
        for (const auto& dir : directions)
        {
            grid[r][c] = '0';
            dfs(grid, r + dir.first, c + dir.second);
        }
    }
};
