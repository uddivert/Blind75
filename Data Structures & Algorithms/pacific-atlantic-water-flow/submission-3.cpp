class Solution {
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROWS = heights.size();
        int COLS = heights[0].size();
        vector<vector<bool>> pacific(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atlantic(ROWS, vector<bool>(COLS, false));

        for (int r = 0; r < ROWS; r ++)
        {
            dfs(r, 0, pacific, heights); 
            dfs(r, COLS -1, atlantic, heights); 
        }

        for (int c = 0; c < COLS; c ++)
        {
            dfs(0, c, pacific, heights);
            dfs(ROWS -1, c, atlantic, heights);
        }

        vector< vector<int>> result;
        for (int r = 0; r < ROWS; r ++)
        {
            for (int c = 0; c < COLS; c ++)
            {
                if (pacific[r][c] && atlantic[r][c])
                {
                    result.push_back({r, c});
                }
            }
        }
        return result;
    }

    void dfs( int r, int c, vector<vector<bool>>& visited, vector<vector<int>>& heights)
    {
        visited[r][c] = true;
        for (const auto& dir : directions )
        {
            int nr = r + dir.first;
            int nc = c + dir.second;
            if (nr >= 0 && nr < heights.size() &&
                nc >= 0 && nc < heights[0].size() &&
                heights[nr][nc] >= heights[r][c] )
                {
                    if (visited[nr][nc])
                    {
                        continue;
                    }
                dfs(nr, nc, visited, heights);
                }
        }
    }
};
