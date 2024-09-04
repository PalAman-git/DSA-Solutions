//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    int cycle(int src,vector<int> adj[],vector<int> &visited)
    {
        queue<pair<int,int>> q;
        q.push({src,-1});//parent of src is not given
        visited[src] = 1 ; //src has been visited
        
        while(!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto i: adj[node])
            {
                if(!visited[i])
                {
                    q.push({i,node});
                    visited[i] = 1;
                }
                else if(i!= parent)
                {
                    return 1;
                }
            }
        }
        return 0;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V,0);
        int ans;
        
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(cycle(i,adj,visited)) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends