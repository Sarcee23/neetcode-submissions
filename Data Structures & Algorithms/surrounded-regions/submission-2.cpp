class Solution {
    vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        if (rows == 0) return;
        int cols = board[0].size();

        // Step 1: Run DFS from all border 'O's
        for (int r = 0; r < rows; r++) {
            if (board[r][0] == 'O') dfs(board, rows, cols, r, 0);
            if (board[r][cols-1] == 'O') dfs(board, rows, cols, r, cols-1);
        }
        for (int c = 0; c < cols; c++) {
            if (board[0][c] == 'O') dfs(board, rows, cols, 0, c);
            if (board[rows-1][c] == 'O') dfs(board, rows, cols, rows-1, c);
        }

        // Step 2: Flip all remaining 'O' -> 'X' (captured), and '#' -> 'O' (safe)
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (board[r][c] == 'O') board[r][c] = 'X';
                if (board[r][c] == '#') board[r][c] = 'O';
            }
        }
    }

private:
    void dfs(vector<vector<char>>& board, int rows, int cols, int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != 'O') {
            return;
        }
        board[r][c] = '#'; // mark as safe
        for (auto dir : dirs) {
            int dr = r + dir[0];
            int dc = c + dir[1];
            dfs(board, rows, cols, dr, dc);
        }
    }
};
