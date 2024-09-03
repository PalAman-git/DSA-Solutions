class Solution {
public:
    void dfs(int i,int j,vector<vector<char>> &grid,vector<vector<int>> &visited)
    {
        if(i<grid.size() && j<grid[0].size() && grid[i][j] =='1' && !visited[i][j])
        {
            visited[i][j] = 1;
            dfs(i+1,j,grid,visited);
            dfs(i,j+1,grid,visited);
            dfs(i,j-1,grid,visited);
            dfs(i-1,j,grid,visited);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        int islands = 0;

        vector<vector<int>> visited(rows,vector<int>(columns,0));
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<columns;j++)
            {
                if(grid[i][j] == '1' && !visited[i][j])
                {
                    islands++;
                    dfs(i,j,grid,visited);
                }
            }
        }
        return islands;
    }
};