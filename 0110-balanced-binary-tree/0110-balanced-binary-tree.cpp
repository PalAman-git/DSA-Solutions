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
private:
    int height(TreeNode* root)
    {
        if(root == NULL)return 0;

        int left = height(root -> left);
        int right = height(root -> right);

        return max(left,right) + 1;
    }

    bool solve(TreeNode* root)
    {
        if(root == NULL) return true;

        int leftH = height(root -> left);
        int rightH = height(root -> right);

        if(abs(leftH-rightH) > 1) return false;

        bool left = solve(root -> left);
        bool right = solve(root -> right);

        if(!left || !right) return false;

        return true;
    }
public:
    bool isBalanced(TreeNode* root) {
        return solve(root);
    }
};