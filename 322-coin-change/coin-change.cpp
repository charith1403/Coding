class Solution {
public:

    int helper(int index, vector<int>& coins, int amount, vector<vector<int>> &dp)
    {
        if(index >= coins.size() || amount < 0)
        {
            return INT_MAX - 1;
        }

        if(amount == 0)
        {
            return 0;
        }

        if(dp[amount][index] != -1)
        {
            return dp[amount][index];
        }

        int dontTake = 0 + helper(index+1,coins,amount,dp);
        int take = 1 + helper(index,coins,amount - coins[index],dp);
        
        dp[amount][index] = min(dontTake,take);
        return dp[amount][index];

    }

    int coinChange(vector<int>& coins, int amount) {
        
        vector<vector<int>> dp(amount+1,vector<int>(coins.size()+1,-1));
        long long ans = helper(0,coins,amount,dp);
        if(ans == INT_MAX - 1)
        {
            return -1;
        }

        return (int)ans;
    }
};