class Solution {
public:
    typedef pair<long long,int> P;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        for(auto &it: roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        priority_queue<P,vector<P>,greater<P>> pq;
        vector<long long> dist(n,LLONG_MAX),ways(n,0);
        ways[0] = 1;
        dist[0] = 0;
        pq.push({0,0});
        int mod = (int)(1e9+7);

        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            int node = it.second;
            long long time = it.first;

            for(auto &neighbour : adj[node])
            {
                int adjNode = neighbour.first;
                int edgW = neighbour.second;

                //first time reaching the node with shortest path
                if(time + edgW < dist[adjNode])
                {
                    dist[adjNode] = time + edgW;
                    pq.push({time+edgW,adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(time + edgW == dist[adjNode]) ways[adjNode] = (ways[adjNode] + ways[node])%mod;
            }
        }
        return ways[n-1]%mod;
    }
};