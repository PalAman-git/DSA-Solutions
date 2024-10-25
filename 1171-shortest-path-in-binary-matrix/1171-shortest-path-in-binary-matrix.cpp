class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
        queue<pair<int,pair<int,int>>> q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0] = 1;
        q.push({1,{0,0}});

        int dr[] = {-1,-1,+1,+1,0,0,-1,+1};
        int dc[] = {-1,+1,-1,+1,-1,+1,0,0};

        while(!q.empty())
        {
            auto it = q.front();
            q.pop();

            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;

            for(int i=0;i<8;i++)
            {
                int nrow = row + dr[i];
                int ncol = col + dc[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 0 && dist[nrow][ncol] > dis + 1)
                {
                    dist[nrow][ncol] = dis+1;
                    q.push({dis+1,{nrow,ncol}});
                }
            }
        }
        if(dist[n-1][m-1] == 1e9) return -1;

        return dist[n-1][m-1];
    }
};