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
    int level[1000001];
    int height[1000001];
    // int levelMaxHt[1000001];
    // int levelSecondMaxHt[1000001];
    pair<int,int> maxHt[1000001];

    int makeNodeDetails(TreeNode* root,int lvl)
    {
        if(!root) return 0;

        level[root -> val] = lvl;
        height[root -> val] = max(makeNodeDetails(root -> left,lvl+1),makeNodeDetails(root -> right,lvl+1)) + 1;

        if(maxHt[lvl].first < height[root -> val]){
            maxHt[lvl].second = maxHt[lvl].first;
            maxHt[lvl].first = height[root -> val];
        }
        else if(maxHt[lvl].second < height[root -> val]) maxHt[lvl].second = height[root -> val];

        return height[root -> val];

    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        makeNodeDetails(root,0);

        vector<int> result;
        for(const auto &node : queries)
        {
            int L = level[node];
            int H = (maxHt[L].first == height[node] ? maxHt[L].second : maxHt[L].first);
            result.push_back(L+H-1);
        }
        return result;
    }
};