class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());                    // ➊ ascending for pruning
        vector<vector<int>> res;
        vector<int> path;
        dfs(nums, 0, target, path, res);
        return res;
    }

private:
    void dfs(const vector<int>& a, int idx,
             int remaining,                  // ➋ remaining target instead of curSum
             vector<int>& path,
             vector<vector<int>>& res) {
        if (remaining == 0) {                // 🎯 found one
            res.push_back(path);
            return;
        }
        if (idx == a.size() || a[idx] > remaining) return; // ➌ prune

        // ➍ Choice 1: take current element (reuse allowed ⇒ stay on idx)
        path.push_back(a[idx]);
        dfs(a, idx, remaining - a[idx], path, res);
        path.pop_back();

        // ➎ Choice 2: skip current element (move to next)
        dfs(a, idx + 1, remaining, path, res);
    }
};
