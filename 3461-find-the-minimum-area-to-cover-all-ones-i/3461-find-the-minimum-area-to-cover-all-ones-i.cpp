class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {

        size_t n = grid.size();
        size_t m = grid[0].size();

        int minRow = n,maxRow = -1;
        int minCol = m,maxCol = -1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    minRow = min(minRow,i);
                    maxRow = max(maxRow,i);
                    minCol = min(minCol,j);
                    maxCol = max(maxCol,j);
                }
            }
        }

        //If no 1 found then return zero
        if(minRow > maxRow || minCol > maxCol) return 0;

        int length = maxCol - minCol + 1;
        int breadth = maxRow - minRow + 1;

        return length * breadth;
    }
};