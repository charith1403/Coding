class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        vector<pair<int, int>> arr;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    arr.push_back({i, j});
                }
            }
        }

        for (auto pos : arr) {
            int ipos = pos.first;
            int jpos = pos.second;

            for (int i = 0; i < matrix.size(); i++)
            {
                matrix[i][jpos] = 0;
            }

            for(int j=0; j< matrix[0].size();j++)
            {
                matrix[ipos][j] = 0;
            }
        }
    }
};