class Solution {
public:
    bool solve(int index, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(target==0) return true;
        if(index<0 || target<0) return false;

        if(dp[index][target] != -1) return dp[index][target];

        return dp[index][target] = solve(index-1, target, nums, dp)||solve(index-1, target-nums[index], nums, dp);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int x : nums) sum += x;

        if (sum % 2 != 0) return false; 
        
        int target = sum/2;

        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        return solve(n-1, target, nums, dp);
    }
};