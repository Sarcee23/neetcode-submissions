class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxArea = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    int area = dfs(grid, r, c);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }

    int dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == 0) {
            return 0;
        }

        grid[r][c] = 0; // Mark as visited
        int area = 1;

        int directions[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        for (int i = 0; i < 4; i++) {
            area += dfs(grid, r + directions[i][0], c + directions[i][1]);
        }

        return area;
    }
};
