class Solution {
public:
    int solve(vector<int>& cost, int n, vector<int>& dp){
        if(n<=1) return 0;

        if(dp[n] != -1) return dp[n];

        return dp[n] = min(cost[n-1]+solve(cost, n-1, dp), cost[n-2]+solve(cost, n-2, dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size()+1, -1);
        return solve(cost, cost.size(), dp);
    }
};