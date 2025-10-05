class Solution {
public:
    void uniquePath(int i,int j, int m,int n, int &ans, vector<vector<int>> &dp)
    {
        if(i > m || j > n)
        {
            return;
        }

        if(i == m && j == n)
        {
            ans++;
            return;
        }

        if(dp[i][j] != -1)
        {
            ans += dp[i][j];
            return;
        }

        int dx[] = {1,0};
        int dy[] = {0,1};
        int diffAns = 0;

        for(int k=0;k<2;k++)
        {
            int nrow = i + dx[k];
            int ncol = j + dy[k];
            int prevAns = ans;
            uniquePath(nrow,ncol,m,n,ans,dp);
            diffAns += ans - prevAns;
        }

        dp[i][j] = diffAns;
        return;
    }

    int uniquePaths(int m, int n) {
        int ans = 0;
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        uniquePath(0,0,m-1,n-1,ans,dp);
        return ans;
    }
}; 