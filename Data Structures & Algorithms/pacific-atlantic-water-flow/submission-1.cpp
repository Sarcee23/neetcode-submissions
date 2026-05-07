class Solution {
    private:
    vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
    void bfs(queue<pair<int,int>> &q,vector<vector<bool>>&ocean, vector<vector<int>>&heights){
        int rows = heights.size();
        int cols = heights[0].size();
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
             ocean[r][c] = true;
            for(auto dir: directions){
                int dr = r+dir[0];
                int dc = c+ dir[1];
               if(dr>=0 && dr<rows && dc>=0 && dc<cols &&
   !ocean[dr][dc] &&
   heights[dr][dc] >= heights[r][c]) {
    ocean[dr][dc] = true;  
    q.push({dr,dc});
}

            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<bool>> pac(rows,vector<bool>(cols,false));
        vector<vector<bool>> atl(rows,vector<bool>(cols,false));
        queue<pair<int,int>> pacQueue,atlQueue;
     for(int c=0;c<cols;c++){
    pacQueue.push({0,c});
    pac[0][c] = true;
    atlQueue.push({rows-1,c});
    atl[rows-1][c] = true;
}
for(int r=0;r<rows;r++){
    pacQueue.push({r,0});
    pac[r][0] = true;
    atlQueue.push({r,cols-1});
    atl[r][cols-1] = true;
}

        bfs(pacQueue,pac,heights);
        bfs(atlQueue,atl,heights);
        vector<vector<int>> res;
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(pac[r][c] && atl[r][c] ){
                    res.push_back({r,c});
                }
            }
        }
        return res;
    }

};
