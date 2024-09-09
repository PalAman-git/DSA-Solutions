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
    int maxDepth(TreeNode* root) {
        //using DFS

        // if(root == NULL)return 0;
        // int leftdepth = maxDepth(root -> left);
        // int rightdepth = maxDepth(root -> right);
        // return max(leftdepth,rightdepth) + 1; 

        //using BFS
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        int ans=0;
        if(root == NULL) return ans;

        while(!q.empty())
        {
            TreeNode* frontNode = q.front().first;
            int depth = q.front().second;
            ans = max(depth,ans);
            q.pop();

            if(frontNode -> left) q.push({frontNode -> left,depth+1});
            if(frontNode -> right) q.push({frontNode -> right,depth+1});
        }
        return ans;
    }
};