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
        bool ans = dfs(root,0,targetSum);
        return ans;
    }
    bool dfs(TreeNode* node, int curSum, int targetSum){
        if(node == nullptr)return false;
        curSum += node->val;

        if(node->left == nullptr and node->right ==nullptr){
            return curSum == targetSum;
        }

        return dfs(node->left,curSum,targetSum) || dfs(node->right, curSum,targetSum);
    }
};