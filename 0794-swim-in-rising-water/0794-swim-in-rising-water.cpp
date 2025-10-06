class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>> pq; //elevation,row,col
        vector<vector<int>>visited(n,vector<int>(n,0));

        //start at 0,0
        pq.push({grid[0][0],0,0});
        visited[0][0] = 1;


        //directions (up,down,left,right)
        int dr[4] = {-1,1,0,0};
        int dc[4] = {0,0,-1,1};

        int answer = 0;

        while(!pq.empty()){
            auto [elev,r,c] = pq.top();
            pq.pop();

            answer = max(answer,elev);

            if(r == n-1 && c == n-1) return answer;

            for(int i=0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nc >= 0 && nr < n && nc < n && !visited[nr][nc]){
                    visited[nr][nc] = 1;
                    pq.push({grid[nr][nc],nr,nc});
                }
            }
        }

        return -1;
    }
};