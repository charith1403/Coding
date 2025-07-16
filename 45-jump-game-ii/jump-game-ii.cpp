class Solution {
public:
    int helper(int curr,vector<int> &nums,vector<int> &dp)
    {
        if(curr >= nums.size() - 1)
        {
            return 0;
        }

        if(dp[curr] != -1)
        {
            return dp[curr];
        }

        int ans = INT_MAX;

        for(int i=1;i<=nums[curr];i++)
        {
            int next = INT_MAX;
            next = helper(curr+i,nums,dp);
            if(next != INT_MAX)
            {
                ans = min(ans,1+next);
            }
        }

        dp[curr] = ans;
        return dp[curr];
    }

    int jump(vector<int>& nums) {
        vector<int>dp(nums.size() + 1, -1);
        return helper(0,nums,dp);
    }
};