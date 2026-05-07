class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;
        int time = 0;
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(grid[r][c] == 2){
                    q.push({r,c});
                }
                if(grid[r][c] == 1){
                    fresh++;
                }
            }
        }
        vector<pair<int,int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty() && fresh>0){
                int length = q.size();
                for(int i=0;i<length;i++){
                        auto [r,c] = q.front();
                        q.pop();
                        for(const auto dir: directions){
                            int newRow = r +dir.first;
                            int newCol = c+ dir.second;
                            if(newRow >=0 and newRow<grid.size() and newCol >=0 and newCol<grid[0].size() && grid[newRow][newCol] == 1){
                                grid[newRow][newCol] = 2;
                                q.push({newRow,newCol});
                                fresh--;
                            }
                        }
                }
                time++;
        }
        return fresh == 0? time: -1;
    }
};
