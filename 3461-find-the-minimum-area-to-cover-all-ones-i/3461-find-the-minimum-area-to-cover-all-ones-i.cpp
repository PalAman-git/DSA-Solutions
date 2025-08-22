class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {

        size_t n = grid.size();
        size_t m = grid[0].size();

        vector<int> trackRow(n, 0);
        vector<int> trackCol(m, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    trackRow[i] = 1;
                    trackCol[j] = 1;
                }
            }
        }

        // now we have to find the first and last occurence of 1 in both of the
        // vector as all the zero between one's will not matter as we have to
        // make a rectange with smallest area which contains all the 1's in the
        // grid

        int RowfirstOccurence = INT_MIN;
        int RowlastOccurence = 0;
        int ColfirstOccurence = INT_MIN;
        int CollastOccurence = 0;

        for(int i=0;i<n;i++){
            if(trackRow[i] == 1){
                RowfirstOccurence = i;
                break;
            }
        }

        for(int i=0;i<n;i++){
            if(trackRow[i] == 1){
                RowlastOccurence = i;
            }
        }

        if(RowfirstOccurence == INT_MIN) return 0;
        int breadth = RowlastOccurence - RowfirstOccurence + 1;

        for(int i=0;i<m;i++){
            if(trackCol[i]== 1){
                ColfirstOccurence = i;
                break;
            }
        }

        for(int i=0;i<m;i++){
            if(trackCol[i] == 1){
                CollastOccurence = i;
            }
        }

        int length = CollastOccurence - ColfirstOccurence + 1;

        return length * breadth;
    }
};