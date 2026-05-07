class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subset;
        vector<int>curr;
        backtrack(nums,subset,0,curr);
        return subset;
    }
    void backtrack(vector<int>&nums,vector<vector<int>>&res,int i,vector<int>&subset){
      if(i == nums.size()){
        res.push_back(subset);
        return;
      }
      subset.push_back(nums[i]);
      backtrack(nums,res,i+1,subset);
      subset.pop_back();
      backtrack(nums,res,i+1,subset);
    }
};
