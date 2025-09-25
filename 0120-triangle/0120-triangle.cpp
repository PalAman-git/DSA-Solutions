class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
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