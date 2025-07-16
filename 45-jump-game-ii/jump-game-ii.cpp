class Solution {
public:
    void helper(int curr, vector<int>& nums, vector<int>& dp, int& ans) {
        if (curr >= nums.size() - 1) {
            ans = 0;
            return;
        }

        if (dp[curr] != -1) {
            ans = dp[curr];
            return;
        }

        int min_jumps = INT_MAX;

        for (int i = 1; i <= nums[curr]; i++) {
            int next_ans = INT_MAX;
            helper(curr + i, nums, dp, next_ans);

            if (next_ans != INT_MAX) {
                min_jumps = min(min_jumps, 1 + next_ans);
            }
        }

        dp[curr] = min_jumps;
        ans = dp[curr];
    }

    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        int ans = INT_MAX;
        helper(0, nums, dp, ans);
        return ans;
    }
};
