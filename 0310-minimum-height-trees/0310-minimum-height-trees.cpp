class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(n);
        queue<int> q;

        if(n == 1) {
            return {0};
        }

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 1) {
                q.push(i);
            }
        }

        while (n > 2) {
            int size = q.size();

            //number of nodes which are going to be processed = size so substract it from the total number
            n -= size;
            
            while(size--)
            {
                int node = q.front();
                q.pop();

                for(auto i : adj[node])
                {
                    indegree[i]--;
                    if(indegree[i] == 1) q.push(i);
                }
            }
        }

        vector<int> ans;
        while(!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};