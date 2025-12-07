class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // bottom up - with space optimization
        int n = cost.size();
        vector<int> dp(n+1, -1);
        int dp1 = 0, dp2 = 0, dp3;
        for(int i = 2; i<=n; i++){
            dp3 = min(cost[i-1]+dp2, cost[i-2]+dp1);
            dp1 = dp2;
            dp2 = dp3;
        }
        return dp3;
    }
};