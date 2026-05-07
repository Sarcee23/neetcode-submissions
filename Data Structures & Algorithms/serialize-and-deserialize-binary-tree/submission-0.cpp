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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL){
            return "#";
        }
        return to_string(root->val)+ "," +serialize(root->left) + ","+ serialize(root->right);    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
     
        stringstream s(data);
        return makeDeserialized(s);
    }

    TreeNode* makeDeserialized(stringstream&s){
        string str;
        getline(s,str,',');
        if(str  == "#"){
            return NULL;
        }
        else{
            TreeNode* root = new TreeNode(stoi(str));
            root->left = makeDeserialized(s);
            root->right = makeDeserialized(s);
            return root;
        }
    }
};
