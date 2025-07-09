class Solution {
public:

    int helper(int index, vector<int> &nums,vector<int>&dp)
    {
        if(index >= nums.size())
        {
            return 0;
        }

        if(dp[index] != -1)
        {
            return dp[index];
        }

        int notRob = 0 + helper(index+1,nums,dp);
        int rob = nums[index] + helper(index+2,nums,dp);

        dp[index] = max(rob,notRob);
        return dp[index];
    }
    int rob(vector<int>& nums) {
        
        vector<int> dp(nums.size()+1,-1);
        return helper(0,nums,dp);
    }
};