class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> ans;
        ans.push_back({1});

        for(int i=0;i<numRows-1;i++)
        {
            int prev = 0;
            vector<int> arr;

            for(int j=0;j<ans[i].size();j++)
            {
                arr.push_back(ans[i][j] + prev);
                prev = ans[i][j];
            }
            int next = ans[i][ans[i].size() - 1];
            arr.push_back(next);
            ans.push_back(arr);
        }

        return ans;
        
    }
};