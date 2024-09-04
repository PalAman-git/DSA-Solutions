class Solution {
private:
   
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,1,0,-1};
        queue<pair<int,int>> q;

        for(int j=0;j<m;j++)
        {
            //first row
            if(grid[0][j] == 1)
            {
                visited[0][j] = 1;
                q.push({0,j});
            }

            //last row
            if(grid[n-1][j] == 1)
            {
                visited[n-1][j] = 1;
                q.push({n-1,j});
            }
        }

        for(int i=0;i<n;i++)
        {
            //first column
            if(grid[i][0] == 1)
            {
                visited[i][0] = 1;
                q.push({i,0});
            }
            
            //last column
            if(grid[i][m-1] == 1)
            {
                visited[i][m-1] = 1;
                q.push({i,m-1});
            }
        }

        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0;i<4;i++)
            {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && grid[nrow][ncol] == 1)
                {
                    visited[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }

        int count = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j] && grid[i][j] == 1)
                {
                    count++;
                }
            }
        }
        return count;
    }
};