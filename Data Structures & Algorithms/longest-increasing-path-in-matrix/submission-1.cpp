class Solution {
private:
    vector<vector<int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};

public:
    int dfs(vector<vector<int>>&matrix,int r,int c,vector<vector<int>>&memo){
           int rows = matrix.size();
            int cols = matrix[0].size();
        if(memo[r][c]!=0){
            return memo[r][c];
        }
        int res = 1;
        for(auto dir : dirs){
            int newRow = r + dir[0];
            int newCol = c + dir[1];
            if(newRow>=0 && newRow<rows && newCol >=0 && newCol<cols && matrix[newRow][newCol]>matrix[r][c]){
                res  = max(res,1+dfs(matrix,newRow,newCol,memo));
            }
        }
        memo[r][c] = res;
        return res;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
            int rows = matrix.size();
    int cols = matrix[0].size();
        if(matrix.empty()){
            return 0;
        }    
        int maxDist = 0;
        vector<vector<int>> memo(rows,vector<int>(cols,0));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                maxDist = max(maxDist,dfs(matrix,i,j,memo));
            }
        }
        return maxDist;
    }
};
