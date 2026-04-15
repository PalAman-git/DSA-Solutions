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
    void dfs(TreeNode* root,int currDepth,int targetDepth,int val){
        if(!root) return;

        if(currDepth + 1 == targetDepth){
            TreeNode* left = root -> left;
            TreeNode* right = root -> right;

            root -> left = new TreeNode(val);
            root -> right = new TreeNode(val);

            root -> left -> left = left;
            root -> right -> right = right;

            return;
        }

        dfs(root -> left,currDepth+1,targetDepth,val);
        dfs(root -> right,currDepth+1,targetDepth,val);
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* head = new TreeNode(val);
            head -> left = root;
            return head;
        }

        dfs(root,1,depth,val);
        return root;
    }
};