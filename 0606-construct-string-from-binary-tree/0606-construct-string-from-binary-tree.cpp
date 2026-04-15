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
    void dfs(TreeNode* root,string &output){

        output += to_string(root -> val);

        //if both child exist
        if(root -> left && root -> right){
            output += "(";
            dfs(root -> left,output);
            output += ")";

            output += "(";
            dfs(root -> right,output);
            output += ")";
        }
        else if(root -> left){
            output += "(";
            dfs(root -> left,output);
            output += ")";
        }
        else if(root -> right){
            output += "()";
            output += "(";
            dfs(root -> right,output);
            output += ")";
        }
    }

    string tree2str(TreeNode* root) {
        string output = "";
        dfs(root,output);

        return output;
    }
};