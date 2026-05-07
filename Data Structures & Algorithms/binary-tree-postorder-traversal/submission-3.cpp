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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>res;
        if(!root) return res;
        stack<pair<TreeNode*,bool>>st;
        st.push({root,false});
        while(!st.empty()){
            auto [node,visited] = st.top();
            st.pop();
            if(!node)continue;
            if(visited){
                res.push_back(node->val);
            }
            else{
                //process later 
                st.push({node,true});
                st.push({node->right,false});
                st.push({node->left,false});
            }
            
        }
        return res;


    }
};