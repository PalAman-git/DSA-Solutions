class Solution {
public:

int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int delRow[] = {-1, 0, +1, 0};
    int delCol[] = {0, +1, 0, -1};

    queue<pair<pair<int, int>, int>> q;
    int max_time = 0;

    // Push all initial rotten oranges into the queue with time 0
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 2) {
                q.push({{i, j}, 0});
            }
        }
    }

    // BFS to rot the fresh oranges
    while(!q.empty()) {
        pair<pair<int, int>, int> front = q.front();
        q.pop();

        int row = front.first.first;
        int col = front.first.second;
        int time = front.second;

        max_time = max(time, max_time);

        // Check all 4 directions
        for(int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            // Check boundaries, ensure it's a fresh orange, then rot it
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1) {
                grid[nrow][ncol] = 2; // Mark it as rotten
                q.push({{nrow, ncol}, time + 1});
            }
        }
    }

    // Check if any fresh oranges remain
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 1) {
                return -1; // If there's any fresh orange left
            }
        }
    }

    return max_time;
}
};