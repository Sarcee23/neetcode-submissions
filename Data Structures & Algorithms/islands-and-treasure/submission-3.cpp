
class Solution {
private:
    vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int,int>> q;

        // Step 1: Push all treasure chests (0) into the queue
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }

        // Step 2: BFS expansion
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto &dir : dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                // Check boundaries & only update INF cells
                if (nr >= 0 && nc >= 0 && nr < rows && nc < cols && grid[nr][nc] == INT_MAX) {
                    grid[nr][nc] = grid[r][c] + 1; // update distance
                    q.push({nr, nc});
                }
            }
        }
    }
};

