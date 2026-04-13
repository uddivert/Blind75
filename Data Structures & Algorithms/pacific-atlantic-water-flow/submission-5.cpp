class Solution {
    vector<pair<int, int>> dir {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROWS = heights.size();
        int COLS = heights[0].size();
        vector<vector<bool>> pac(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atl(ROWS, vector<bool>(COLS, false));

        // Search first and last col
        for (int r = 0; r < ROWS; r ++)
        {
            dfs( heights, r, 0, pac );
            dfs(heights, r, COLS - 1, atl );
        }

        // Search first and last row
        for (int c = 0; c < COLS; c ++)
        {
            dfs( heights, 0, c, pac );
            dfs( heights, ROWS -1 , c, atl );
        }

        vector<vector<int>> result;
        for (int r = 0; r < ROWS; r ++)
        {
            for (int c = 0; c < COLS; c ++)
            {
                if (pac[r][c] && atl[r][c])
                {
                    result.push_back({r, c});
                }
            }
        }
        return result;
    }
    void dfs(vector<vector<int>>& heights, int r, int c, vector<vector<bool>>& visited) {
        visited[r][c] = true;
        for (const auto & [dr, dc] : dir)
        {
            int nr =  r + dr;
            int nc = c + dc;

            if (nr < 0 || nc < 0 || nr > heights.size() -1  || nc > heights[0].size() -1 || visited[nr][nc] ||  heights[r][c] > heights[nr][nc])
            {
                continue;
            }
            dfs(heights, nr, nc, visited);
        }
    }
};
