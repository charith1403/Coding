class Solution:
    def uniquePath(self, i:int ,j:int ,m:int ,n:int,dp : list[list[int]]) -> int:
        if(i > m or j > n):
            return 0

        if(i==m and j==n):
            return 1

        if(dp[i][j] != -1):
            return dp[i][j]

        dx:int = [1,0]
        dy:int = [0,1]
        dp[i][j] = 0

        for k in range(0,2):
            nrow:int = i + dx[k]
            ncol:int = j + dy[k]
            dp[i][j] += self.uniquePath(nrow,ncol,m,n,dp)

        return dp[i][j]

    def uniquePaths(self,m:int, n:int) -> int:
        dp = [[-1 for i in range (n)]for j in range (m)]
        return self.uniquePath(0,0,m-1,n-1,dp)
        