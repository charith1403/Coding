class Solution {

    int helper(int curr, int[] nums,int[] dp)
    {
        if(curr >= nums.length - 1)
        {
            return 0;
        }

        if(dp[curr] != -1)
        {
            return dp[curr];
        }

        int ans = Integer.MAX_VALUE;

        for(int i=1;i<=nums[curr];i++)
        {
            int next = Integer.MAX_VALUE;
            next = helper(curr + i,nums,dp);

            if(next != Integer.MAX_VALUE)
            {
                ans = Math.min(ans,1+next);
            }
        }
        dp[curr] = ans;
        return dp[curr];
    }

    public int jump(int[] nums) {

       int dp[] = new int [nums.length + 1];
        Arrays.fill(dp,-1);
        return helper(0,nums,dp);
    }
}