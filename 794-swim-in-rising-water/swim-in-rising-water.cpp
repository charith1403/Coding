class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        // edge case
        if (grid.size() == 1) {
            return 0;
        }

        int n = grid.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        vector<vector<bool>> visited(n,vector<bool>(n, false));

        int ans = max(grid[0][0], grid[n - 1][n - 1]);
        //weight, row, col
        pq.push({ans, 0, 0});
        visited[0][0] = true;

        vector<int> drow = {0, 0, 1, -1};
        vector<int> dcol = {1, -1, 0, 0};
        while (!pq.empty()) {
            vector<int> temp = pq.top();
            pq.pop();
            ans = max(ans, temp[0]);
            int row = temp[1];
            int col = temp[2];

            for (int k = 0; k < 4; k++) {
                int nrow = row + drow[k];
                int ncol = col + dcol[k];

                // reached destinanion
                if (nrow == n - 1 && ncol == n - 1) {
                    return ans;
                }

                if(nrow>=0 && nrow <n && ncol >=0 && ncol < n && visited[nrow][ncol] == 0)
                {
                    pq.push({grid[nrow][ncol], nrow, ncol});
                    visited[nrow][ncol] = true;
                }
               
            }
        }
        return -1;
    }
};