class Solution {
public:
    int rob(vector<int>& nums) {
        // tabulation - iterative
        int n = nums.size();
        if(n == 1) return nums[0];

        int dp1 = 0, dp2 = nums[0], dp3 = nums[0];
        for(int i = 2; i<=n; i++){
            dp3 = max(nums[i-1]+dp1, dp2);
            dp1 = dp2;
            dp2 = dp3;
        }
        return dp3;
    }
};