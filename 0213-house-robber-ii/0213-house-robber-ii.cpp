class Solution {
public:
    // int solve(vector<int>& nums, int n, bool mark, vector<int>& dp){
    //     if(n==0) return 0;
    //     if(!mark && n==1) return nums[0];
    //     else if(n==1) return 0;

    //     if(dp[n] != -1) return dp[n];
    //     if(n==nums.size()){
    //         return dp[n] = max(nums[n-1]+solve(nums, n-2, !mark, dp), solve(nums, n-1, mark, dp));
    //     }
    //     return dp[n] = max(nums[n-1]+solve(nums, n-2, mark, dp), solve(nums, n-1, mark, dp));
    // }

    int solve(vector<int>& nums, int n, vector<int>& dp){
        if(n==0) return 0;
        if(n==1) return nums[0];

        if(dp[n] != -1) return dp[n];

        return dp[n] = max(nums[n-1]+solve(nums, n-2, dp), solve(nums, n-1, dp));
    }

    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        
        vector<int> arr1(nums.begin(), nums.end() - 1);
        vector<int> arr2(nums.begin() + 1, nums.end());

        vector<int> dp1(arr1.size()+1, -1);
        vector<int> dp2(arr2.size()+1, -1);
        return max(solve(arr1, arr1.size(), dp1),solve(arr2,arr2.size(),dp2));
    }
};