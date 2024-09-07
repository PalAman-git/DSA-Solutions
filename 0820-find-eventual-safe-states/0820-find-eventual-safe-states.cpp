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
        int n = graph.size();
        int m = graph[0].size();
        vector<int> visited(n,0);
        vector<int> check(n,0);
        vector<int> pathVisited(n,0);

        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(i,visited,check,pathVisited,graph);
            }
        }

        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(check[i] == 1)
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};