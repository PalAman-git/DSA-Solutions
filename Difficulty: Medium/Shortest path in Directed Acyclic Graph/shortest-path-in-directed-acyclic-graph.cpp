//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  private:
  void dfs_topoSort(int src,vector<int>&vis,stack<int>&st,vector<pair<int,int>>adj[]){
      vis[src] = 1;
      // go to all adjacent node
      for(auto it : adj[src]){
          int node = it.first;
          if(vis[node]==0){
              dfs_topoSort(node,vis,st,adj);
          }
      }
      st.push(src);
  }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // Step-1 : Apply TopoSort to make it linear
        // Calculate the distance
        vector<pair<int,int>>adj[N];
        for(int i=0;i<M;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int d = edges[i][2];
            adj[u].push_back({v,d});
        }
        vector<int>vis(N);
        stack<int>st; // topoSort
        for(int i=0;i<N;i++){
            if(vis[i]==0)
               dfs_topoSort(i,vis,st,adj);
        }
        
        // Step - 2: calculate shortest distance
        vector<int>dis(N,1e9);
        dis[0] = 0;  // source is 0
        while(!st.empty()){
            int node = st.top();
            st.pop();
            // go to all adjacent node of node
            for(auto it: adj[node]){
                int n = it.first;
                int d = it.second;
                dis[n] = min(dis[n],dis[node]+d);
            }
        }
        for(int i=0;i<N;i++){
            if(dis[i]==1e9) dis[i] = -1;
        }
     return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends