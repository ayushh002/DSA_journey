class Solution {
public:
    int solve(int amount, vector<int>& coins, int index, vector<vector<int>>& dp){
        if(index<0 || amount<0)
            return 0;

        if(amount==0)
            return 1;

        if(dp[index][amount] != -1) return dp[index][amount];

        return dp[index][amount] = solve(amount-coins[index], coins, index, dp) + solve(amount, coins, index-1, dp);

    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, -1));
        return solve(amount, coins, coins.size()-1, dp);
    }
};