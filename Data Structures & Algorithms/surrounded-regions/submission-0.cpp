class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int ROWS = board.size();
        if (ROWS == 0) {
            return;
        }
        int COLS = board[0].size();
        
        // Step 1: Mark non-capturable 'O's connected to the border
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (board[r][c] == 'O' && (r == 0 || c == 0 || r == ROWS - 1 || c == COLS - 1)) {
                    dfs(board, r, c);
                }
            }
        }
        
        // Step 2: Convert remaining 'O's to 'X'
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                }
            }
        }
        
        // Step 3: Convert '#' back to 'O'
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (board[r][c] == '#') {
                    board[r][c] = 'O';
                }
            }
        }
    }

    void dfs(vector<vector<char>>& board, int r, int c) {
        int ROWS = board.size();
        int COLS = board[0].size();
        if (r < 0 || r >= ROWS || c < 0 || c >= COLS || board[r][c] != 'O') {
            return;
        }
        board[r][c] = '#';  // Mark this 'O' as non-capturable
        dfs(board, r + 1, c);
        dfs(board, r - 1, c);
        dfs(board, r, c + 1);
        dfs(board, r, c - 1);
    }
};

