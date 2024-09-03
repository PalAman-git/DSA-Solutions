class Solution {
public:
    void flood_fill(int row,int col,int initial_color,int color,vector<vector<int>> &image,vector<vector<int>> &ans,int deltaRow[],int deltaCol[])
    {
        ans[row][col] = color;


        int n = image.size();
        int m = image[0].size();
        for(int i=0;i<4;i++)
        {
            int nrow = row + deltaRow[i];
            int ncol = col + deltaCol[i];

            if(nrow >=0 && nrow < n && ncol >=0 && ncol <m && image[nrow][ncol] == initial_color && ans[nrow][ncol] != color)
            {
                flood_fill(nrow,ncol,initial_color,color,image,ans,deltaRow,deltaCol);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int i, int j, int color) {
       vector<vector<int>> ans = image;

        int initial_color = image[i][j];
        int deltaRow[] = {-1,0,+1,0};
        int deltaCol[] = {0,1,0,-1};
        flood_fill(i,j,initial_color,color,image,ans,deltaRow,deltaCol);

        return ans;
    }
};