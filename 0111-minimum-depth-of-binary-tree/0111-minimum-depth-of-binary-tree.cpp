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
    int minDepth(TreeNode* root) {
        // if(root == NULL) return 0;
        // if(root -> left == NULL && root -> right == NULL) return 1;

        // if(!root -> left) return minDepth(root -> right) + 1;
        // if(!root -> right) return minDepth(root -> left) + 1;

        // int lheight = minDepth(root -> left);
        // int rheight = minDepth(root -> right);

        // return min(lheight,rheight) + 1;

        //Using the bfs
        if(!root) return 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});

        while(!q.empty())
        {
            TreeNode* node = q.front().first;
            int depth = q.front().second;
            q.pop();

            if(node -> left == NULL && node -> right == NULL) return depth;

            if(node -> left) q.push({node -> left,depth+1});
            if(node -> right) q.push({node -> right,depth+1});
        }
        return 0;
    }
};