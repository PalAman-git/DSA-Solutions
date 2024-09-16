/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root -> left,p,q);
        TreeNode* right = lowestCommonAncestor(root -> right,p,q);

        //left mein nhi mila
        if(left == NULL) return right;

        //right mein nhi mila
        else if(right == NULL) return left;

        //agr dono null nhi hai to mtlb ye root hi lca hai
        else return root;
    }
};