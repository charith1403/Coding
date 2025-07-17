class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int high = (matrix.size() * matrix[0].size()) - 1;

        while(low <= high)
        {
            int mid = (low + high)/2;
            int r = mid / matrix[0].size();
            int c = mid % matrix[0].size();

            if(matrix[r][c] == target)
            {
                return true;
            }
            else if(matrix[r][c] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return false;
    }
};