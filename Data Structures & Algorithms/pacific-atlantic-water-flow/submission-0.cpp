class Solution {
private:
    void dfs(int r, int c, unordered_set<int>& visit, int prevHeight, int ROWS, int COLS, vector<vector<int>>& heights) {
        int coord = r * COLS + c;
        if (r < 0 || r == ROWS || c < 0 || c == COLS || heights[r][c] < prevHeight || visit.count(coord)) {
            return;
        }
        visit.insert(coord);
        dfs(r + 1, c, visit, heights[r][c], ROWS, COLS, heights);
        dfs(r - 1, c, visit, heights[r][c], ROWS, COLS, heights);
        dfs(r, c + 1, visit, heights[r][c], ROWS, COLS, heights);
        dfs(r, c - 1, visit, heights[r][c], ROWS, COLS, heights);
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROWS = heights.size();
        int COLS = heights[0].size();

        unordered_set<int> pac, atl;

        // Traverse along the rows
        for (int i = 0; i < ROWS; i++) {
            dfs(i, 0, pac, heights[i][0], ROWS, COLS, heights);
            dfs(i, COLS - 1, atl, heights[i][COLS - 1], ROWS, COLS, heights);
        }

        // Traverse along the columns
        for (int j = 0; j < COLS; j++) {
            dfs(0, j, pac, heights[0][j], ROWS, COLS, heights);
            dfs(ROWS - 1, j, atl, heights[ROWS - 1][j], ROWS, COLS, heights);
        }

        vector<vector<int>> res;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                int coord = i * COLS + j;
                if (pac.count(coord) && atl.count(coord)) {
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }
};

