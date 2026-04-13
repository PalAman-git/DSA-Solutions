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
    void solve(TreeNode* root,int remainingSum,vector<int> &currentPath,vector<vector<int>> &output){
        if(root == NULL) return;

        if(root -> left == NULL && root -> right == NULL){
            if(remainingSum == root -> val){
                currentPath.push_back(root -> val);
                output.push_back(currentPath);
                currentPath.pop_back();
            }
            return;
        }

        remainingSum -= root -> val;
        currentPath.push_back(root -> val);

        solve(root -> left,remainingSum,currentPath,output);
        solve(root -> right,remainingSum,currentPath,output);

        currentPath.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> currentPath;
        vector<vector<int>> output;

        solve(root,targetSum,currentPath,output);

        return output;
    }
};