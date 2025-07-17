class Solution {

    public boolean helper(int index,int[] nums, int [] dp)
    {
        if(index >= nums.length -1)
        {
            return true;
        }

        if(dp[index] != -1)
        {
            return dp[index] == 1;
        }

        boolean flag = false;

        for(int i=1;i<=nums[index];i++)
        {
            if(helper(index+i,nums,dp))
            {
                flag = true;
                break;
            }
        }

        if(flag) dp[index] = 1;
        else dp[index] = 0;

        return flag;
    }

    public boolean canJump(int[] nums) {
        int dp[] = new int [nums.length +1];
        Arrays.fill(dp,-1);

        return helper(0,nums,dp);
    }
}