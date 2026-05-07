class Solution {
    const int INF = 2147483647;
    const vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
            int rows = grid.size();
            int cols = grid[0].size();
            for(int r=0;r<rows;r++){
                for(int c=0;c<cols;c++){
                    if(grid[r][c] == 0){
                   dfs(grid,rows,cols,r,c,0);}
                }
            }
    }
    void dfs(vector<vector<int>> &grid,int rows,int cols,int r,int c,int dist){
        if(r<0 or r>=rows or c<0 or c>=cols){
            return;
        }
        if(grid[r][c] < dist){
            return;
        }
        grid[r][c] = dist;
        for(auto& dir:dirs){
            dfs(grid,rows,cols,r+dir[0],c+dir[1],dist+1);
        }

    }
};
