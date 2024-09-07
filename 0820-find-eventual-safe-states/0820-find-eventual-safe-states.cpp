class Solution {
private:

bool dfs(int node,vector<int> &visited,vector<int> &check,vector<int> &pathVisited,vector<vector<int>> &graph)
{
    visited[node] = 1;
    pathVisited[node] = 1;
    check[node] = 0;//it is not a safe state yet

    for(auto i: graph[node])
    {
        if(!visited[i])
        {
            if(dfs(i,visited,check,pathVisited,graph) == true) return true;//cycle mil gya
        }
        else if(pathVisited[i] == true)
        {
            return true;
        }
    }

    check[node] = 1;//no cycle found so it is a safe node
    pathVisited[node] = 0;
    return false;
}

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        //using DFS

        // int n = graph.size();
        // int m = graph[0].size();
        // vector<int> visited(n,0);
        // vector<int> check(n,0);
        // vector<int> pathVisited(n,0);

        // for(int i=0;i<n;i++)
        // {
        //     if(!visited[i])
        //     {
        //         dfs(i,visited,check,pathVisited,graph);
        //     }
        // }

        // vector<int> ans;
        // for(int i=0;i<n;i++)
        // {
        //     if(check[i] == 1)
        //     {
        //         ans.push_back(i);
        //     }
        // }

        // return ans;




        //using BFS

        //reversing the given graph
        int N = graph.size();

        vector<int> adj[N];

        for(int i=0;i<N;i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                adj[graph[i][j]].push_back(i);
            }
        }

        //counting the indegree of each node
        vector<int> indegree(N,0);
        for(int i=0;i<N;i++)
        {
            for(auto it: adj[i])
            {
                indegree[it]++;
            }
        }

        //push all the nodes with indegree as 0 in the queue because all of them are terminal nodes
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

            for(auto i: adj[node])
            {
                indegree[i]--;
                if(indegree[i] == 0)
                {
                    q.push(i);
                }
            }
        }

        sort(ans.begin(),ans.end());
        return ans;

    }
};