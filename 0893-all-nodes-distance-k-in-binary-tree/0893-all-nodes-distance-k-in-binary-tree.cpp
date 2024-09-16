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
   void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node->left) {
            parent[node->left] = node;
            q.push(node->left);
        }

        if (node->right) {
            parent[node->right] = node;
            q.push(node->right);
        }
    }
}

//Using DFS
// void solve(TreeNode* root, int k, vector<int>& ans, unordered_map<TreeNode*, TreeNode*>& parent, unordered_map<TreeNode*, bool>& visited) {
//     if (root == NULL || visited[root]) return;

//     // Mark this node as visited
//     visited[root] = true;

//     // If distance k is reached, add the node to the answer
//     if (k == 0) {
//         ans.push_back(root->val);
//         return;
//     }

//     // Recur for the left, right, and parent nodes
//     solve(root->left, k - 1, ans, parent, visited);
//     solve(root->right, k - 1, ans, parent, visited);
    
//     // Move to the parent node
//     if (parent[root] != NULL) {
//         solve(parent[root], k - 1, ans, parent, visited);
//     }
// }

//Using BFS
void solve(TreeNode* root,int k,vector<int> &ans,unordered_map<TreeNode*,TreeNode*> &parent,unordered_map<TreeNode*,bool> &visited)
{
    queue<TreeNode*> q;
    q.push(root);
    int dis = 0;

    while(true)
    {
        int size = q.size();
        if(dis == k) break;
        
        for(int i=0;i<size;i++)
        {
            TreeNode* node = q.front();
            visited[node] = true;
            q.pop();

            if(node -> left && !visited[node -> left]) q.push(node -> left);
            if(node -> right && !visited[node -> right]) q.push(node -> right);
            if(parent[node] && !visited[parent[node]]) q.push(parent[node]);
            
        }
        dis++;
    }

    while(!q.empty())
    {
        ans.push_back(q.front() -> val);
        q.pop();
    }
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*, TreeNode*> parent;  // Map to store the parent of each node
    unordered_map<TreeNode*, bool> visited;     // Map to track visited nodes
    parent[root] = NULL;  // Root node has no parent

    // Mark parents for each node in the tree
    markParent(root, parent);

    vector<int> ans;

    // Start the search from the target node
    solve(target, k, ans, parent, visited);

    return ans;
}

};