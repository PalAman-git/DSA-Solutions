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
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while (curr != NULL) {
            if (curr->left != NULL) {
                // Find the inorder predecessor of the current node
                TreeNode* prev = curr->left;
                while (prev->right != NULL) {
                    prev = prev->right;
                }

                // Link the right subtree of curr to the rightmost node of left subtree
                prev->right = curr->right;

                // Move the left subtree to the right and make left NULL
                curr->right = curr->left;
                curr->left = NULL;
            }

            // Move to the right
            curr = curr->right;
        }
    }
};