class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows= grid.size();
        int cols = grid[0].size();

        queue<pair<int,int>> q;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                }
            }
        }

    vector<vector<int>> dirs  = {{-1,0} , {1,0} ,{0,-1},{0,1}}; 
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int x = row + dirs[i][0];
            int y = col + dirs[i][1];
            if(x<0 || y<0 || x>=rows || y>=cols || grid[x][y]!= INT_MAX){
                continue;
            }
            grid[x][y] = grid[row][col] + 1;
            q.push({x,y});
        }
    }
    }
};
