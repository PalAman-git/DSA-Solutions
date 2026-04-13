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
    int findBottomLeftValue(TreeNode* root) {
        map<int,int> mp;
        queue<pair<TreeNode*,int>> q;

        q.push({root,1});

        while(!q.empty()){
            int size = q.size();

            for(int i=0;i<size;i++){
                TreeNode* node = q.front().first;
                int level = q.front().second;
                q.pop();

                if(mp.find(level) == mp.end()){
                    mp[level] = node -> val;
                }

                if(node -> left){
                    q.push({node -> left,level+1});
                }

                if(node -> right){
                    q.push({node -> right,level+1});
                }
            }
        }

        auto it = mp.rbegin();
        return it -> second;
    }
};