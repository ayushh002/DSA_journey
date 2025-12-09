class Solution {
public:
    int solve(vector<int>& nums, int n, vector<int>& dp){
        if(n==0) return 0;
        if(n==1) return nums[0];

        if(dp[n] != -1) return dp[n];

        return dp[n] = max(nums[n-1]+solve(nums, n-2, dp), solve(nums, n-1, dp));
    }
    int rob(vector<int>& nums) {
        // tabulation - iterative
        int n = nums.size();
        vector<int> dp;
        dp.push_back(0);
        dp.push_back(nums[0]);
        for(int i = 2; i<=n; i++){
            int next = max(nums[i-1]+dp[i-2], dp[i-1]);
            dp.push_back(next);
        }
        return dp[n];
    }
};