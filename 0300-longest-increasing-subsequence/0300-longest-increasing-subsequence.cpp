class Solution {
public:
    int solve(int index, int prev, vector<int>& nums, int n, vector<vector<int>>& dp){
        if(index == n) return 0;

        if (dp[index][prev + 1] != -1)
        return dp[index][prev + 1];

        int notTake = solve(index + 1, prev, nums, n, dp);

        int take = 0;
        if(prev == -1 || nums[index] > nums[prev])
            take = 1+solve(index + 1, index, nums, n, dp);
        
        return dp[index][prev + 1] = max(take, notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        // recursive - Gives TLE
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(0, -1, nums, n, dp);
    }
};