class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        //my first approach was greedy approach but the greedy approach generates the result with comparing local values not globally , so it had
        //to be done with dynamic programming (bottom up approach)

    /** 
        suppose given triangle is [[-1],[2,3][1,-1,-3]];

                -1
            2          3
        1       -1          -3


        we start from the second last row and compute dp[i][j] = dp[i][j] + min(dp[i+1][j],dp[i+1][j+1])
        so in last the triangle will become like this

                 -1
             1          0
        1        -1         -3

        dp[0][0] will give the answer i.e -1;
    */

        for(int row = triangle.size() - 2; row >= 0;row--){

            for(int col = 0; col < triangle[row].size();col++){
                int down = triangle[row+1][col];
                int downRight = triangle[row+1][col+1];

                triangle[row][col] += min(down,downRight);
            }
        }
        return triangle[0][0];
    }
};