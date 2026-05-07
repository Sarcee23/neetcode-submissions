class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows=  grid.size();
        int cols = grid[0].size();
        int numIslands = 0;
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(grid[r][c] == '1'){
                    dfs(grid,rows,cols,r,c);
                    numIslands++;
                }
            }
        }
        return numIslands;
    }
    void dfs(vector<vector<char>>&grid,int rows,int cols,int r,int c){
        if(r<0 or r>=rows or c<0 or c>=cols or grid[r][c] == '0'){
            return;
        }
        grid[r][c] = '0';
        vector<vector<int>>dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        for(int i=0;i<4;i++){
            int dx = r + dirs[i][0];
            int dy= c+ dirs[i][1];
            dfs(grid,rows,cols,dx,dy);
        }
    }
};
