class Solution {
public:
    int solve(vector<int>& nums, int n, bool mark, vector<vector<int>>& dp){
        if(n==0) return 0;
        if(!mark && n==1) return nums[0];
        else if(n==1) return 0;

        if (dp[n][mark] != -1) return dp[n][mark];

        if(n==nums.size()){
            return dp[n][mark] = max(nums[n-1]+solve(nums, n-2, !mark, dp), solve(nums, n-1, mark, dp));
        }
        return dp[n][mark] = max(nums[n-1]+solve(nums, n-2, mark, dp), solve(nums, n-1, mark, dp));
    }


    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        
        vector<vector<int>> dp(nums.size()+1, vector<int>(2, -1));

        return solve(nums, nums.size(), 0, dp);
    }
};