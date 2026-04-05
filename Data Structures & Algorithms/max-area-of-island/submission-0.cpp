class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area = 0;
        for (int r = 0; r < grid.size(); r ++)
        {
            for (int c = 0; c < grid[0].size(); c ++)
            {
                if (grid[r][c] == 1)
                {
                    area = max(dfs(grid, r, c, 0), area);
                }
            }
        }
        return area;
    }

    int dfs(vector<vector<int>>& grid, int r, int c, int area)
    {
        vector<pair<int, int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0)
        {
            return area;
        }
        grid[r][c] = 0;
        for (const auto& dir : direction)
        {
            area = dfs(grid, r + dir.first, c + dir.second, area);
        }
        return area += 1;
    }
};
