class Solution {
public:
    bool canFinish(int N, vector<vector<int>>& prerequisites) {
        //it is similiar question to that of topological sort because in topological sort 
        //if you are given an edge u -> v , you have to make a order in which v comes before u 

        //making the adjacency list
        vector<int>adj[N];
        for(auto i: prerequisites)
        {
            adj[i[0]].push_back(i[1]);
        }

        //mark the indegree of the each node
        vector<int> indegree(N,0);
        for(int i=0;i<N;i++)
        {
            for(auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        queue<int> q;
        //push all the courses having the indegree 0
        for(int i=0;i<N;i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> topo;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto i: adj[node])
            {
                indegree[i]--;
                if(indegree[i] == 0)
                {
                    q.push(i);
                }
            }

        }

        if(topo.size() == N) return true;

        return false;
    }
};