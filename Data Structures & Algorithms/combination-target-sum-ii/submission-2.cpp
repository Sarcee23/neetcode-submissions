class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>res;
        vector<int>subset;
        dfs(candidates,target,res,0,subset);
        return res;
    }
    void dfs(vector<int>& candidates, int remaining,vector<vector<int>>&res,int index,vector<int>&subset ){
        if(remaining == 0){
            res.push_back(subset);
            return;
        }
        if(index == candidates.size() || candidates[index]>remaining){
            return;
        }
        
        subset.push_back(candidates[index]);
        dfs(candidates,remaining-candidates[index],res,index+1,subset);
        subset.pop_back();
        while(index+1<candidates.size() && candidates[index+1]==candidates[index]){
                index++;
        }
        dfs(candidates,remaining,res,index+1,subset);
    }
};
