class Solution {
public:

    bool helper(int index, vector<int>&nums,vector<int> &dp)
    {
        if(index >= nums.size() - 1)
        {
            return true;
        }

        if(dp[index] != -1)
        {
            return dp[index];
        }

        bool flag = false;

        for(int i=1;i<=nums[index];i++)
        {
            if(helper(index + i,nums,dp))
            {
                flag = true;
                break;
            }
        }
        dp[index] = flag;
        return dp[index];

    }

    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, -1);
        return helper(0,nums,dp);
    }
};