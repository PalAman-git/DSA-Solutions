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
    pair<int,int> solve(TreeNode* root){
        if(!root) return {0,0};

        pair<int,int> left = solve(root -> left);
        pair<int,int> right = solve(root -> right);

        int rob = root -> val + left.second + right.second;
        int notRob = max(left.first,left.second) + max(right.first,right.second);

        return {rob,notRob};
    }
    int rob(TreeNode* root) {
        pair<int,int> result = solve(root);

        return max(result.first,result.second);
    }
};