/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int goodNodes(TreeNode* root) {
        return dfs(root->val,root);
    }
    int dfs(int maxVal,TreeNode* node){
        if(!node){
            return 0;
        }
        int res = (node->val >= maxVal) ? 1 : 0;
        maxVal = max(maxVal,node->val);
        res += dfs(maxVal,node->left);
        res += dfs(maxVal,node->right);
        return res;
    }
};
