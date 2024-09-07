class Solution {
public:
    vector<int> findOrder(int N, vector<vector<int>>& prerequisites) {
        //make the adjacency list for the courses 
        //make the indegree for all the courses
        vector<int> indegree(N,0);
        vector<int> adj[N];
        for(auto i : prerequisites)
        {
            adj[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }
        //push all the nodes having indegree as 0
        queue<int> q;
        for(int i=0;i<N;i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        //process the graph
        vector<int> ans;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto i : adj[node])
            {
                indegree[i]--;
                if(indegree[i] == 0)
                {
                    q.push(i);
                }
            }
        }
        if(ans.size() == N) return ans;
        return {};
    }
};