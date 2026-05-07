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
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ans = dfs(root,targetSum);
        return ans;
    }
    bool dfs(TreeNode* node, int targetSum){
        if(node == nullptr)return false;
         targetSum -= node->val;

        if(node->left == nullptr and node->right ==nullptr){
            return targetSum == 0;
        }

        return dfs(node->left,targetSum) || dfs(node->right,targetSum);
    }
};