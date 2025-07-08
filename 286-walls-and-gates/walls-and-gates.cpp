class Solution {
public:
    void wallsAndGates(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, -1, 0, 1};
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow >= 0 && nrow < grid.size() && ncol >=0 && ncol < grid[0].size() && grid[nrow][ncol] == INT_MAX)
                {
                    grid[nrow][ncol] = grid[r][c] + 1;
                    q.push({nrow, ncol});
                }
                
            }
        }
    }
};