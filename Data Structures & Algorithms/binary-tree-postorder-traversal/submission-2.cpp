class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> res;

        if(!root)
            return res;

        stack<TreeNode*> st;

        st.push(root);

        while(!st.empty()) {

            TreeNode* curr = st.top();
            st.pop();

            res.push_back(curr->val);

            // left first
            if(curr->left)
                st.push(curr->left);

            // right second
            if(curr->right)
                st.push(curr->right);
        }

        reverse(res.begin(), res.end());

        return res;
    }
};