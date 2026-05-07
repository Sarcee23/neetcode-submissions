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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        deque<TreeNode*> q;
        if(root){
            q.push_back(root);
        }  

        while(!q.empty()){
            vector<int>level;
             int qsize=q.size();
            for(int i=0;i<qsize;i++){
                TreeNode* currNode = q.front();
                level.push_back(currNode->val);
                q.pop_front();

                if(currNode->left){
                    q.push_back(currNode->left);
                }
                if(currNode->right){
                    q.push_back(currNode->right);
                }

            }
            ans.push_back(level);
        }
        return ans;
    }
};
