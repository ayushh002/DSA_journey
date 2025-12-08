class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp;
        dp.push_back(0);
        dp.push_back(0);

        for(int i = 2; i<=n; i++){
            int num = min(cost[i-1]+dp[i-1], cost[i-2]+dp[i-2]);
            dp.push_back(num);
        }

        return dp[n];
        
    }
};