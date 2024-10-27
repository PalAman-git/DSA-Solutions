class Solution {
public:
    int n,m;

    // int solve(int i,int j,vector<vector<int>> &matrix,vector<vector<int>>& dp)
    // {
    //     if(i >= n || j >= m) return 0;

    //     if(matrix[i][j] == 0) return 0;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     int right = solve(i,j+1,matrix,dp);
    //     int diagonal = solve(i+1,j+1,matrix,dp);
    //     int down = solve(i+1,j,matrix,dp);

    //     return dp[i][j] = 1 + min({right,diagonal,down});
    // }

    int countSquares(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();

        //using the recursion and memoization
        // int result = 0;
        // vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //     {
        //         if(matrix[i][j] == 1) 
        //         result += solve(i,j,matrix,dp);
        //     }
        // }
        // return result;

        //using the bottom up approach
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        //filling the first column
        for(int i=0;i<n;i++)
        {
            if(matrix[i][0] == 1) dp[i][0] = 1;
        }

        //filling the first row
        for(int j=0;j<m;j++)
        {
            if(matrix[0][j] == 1) dp[0][j] = 1;
        }

        //filling the whole table
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(matrix[i][j] == 1)
                {
                    dp[i][j] = 1 + min({dp[i][j-1],dp[i-1][j-1],dp[i-1][j]});
                }
            }
        }

        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(dp[i][j] >= 1) ans += dp[i][j];
            }
        }
        return ans;
    }
};