class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int>current;
        sort(candidates.begin(), candidates.end());
        backtrack(result,candidates,target,current,0);
        return result;
    }

    void backtrack(vector<vector<int>>&result, vector<int>&candidates,int target,vector<int>&current, int index){
        if(target == 0){
             result.push_back(current);
            return;
        }
        if(target<0 || index == candidates.size()){
            return;
        }

     for (int i = index; i < candidates.size(); ++i) {
            if (i > index && candidates[i] == candidates[i - 1]) {
                continue; // Skip duplicates
            }
            current.push_back(candidates[i]);
            backtrack(result, candidates, target - candidates[i], current, i + 1);
            current.pop_back();
        }

    }
};
