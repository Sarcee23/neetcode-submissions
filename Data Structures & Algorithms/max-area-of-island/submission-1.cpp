class Solution {
    private:
    vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows =  grid.size();
        int cols = grid[0].size();
        int area = 0;
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(grid[r][c] == 1){
                     area = max(area,dfs(grid,rows,cols,r,c));
                }
            }
            
        }
        return area;
    }
    int dfs(vector<vector<int>>&grid,int rows,int cols,int r,int c){
        if(r<0 or c<0 or r>=rows or c>=cols or grid[r][c] == 0){
            return 0;
        }
        grid[r][c] = 0;
        int curArea = 1;
        for(int i=0;i<4;i++){
            int dx = r + dirs[i][0];
            int dy = c + dirs[i][1];
            curArea +=dfs(grid,rows,cols,dx,dy); 
        }
        return curArea;
    }
    
};
