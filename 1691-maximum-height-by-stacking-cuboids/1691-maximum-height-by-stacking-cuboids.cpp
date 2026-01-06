class Solution {
public:
    int solve(int index, int prev, vector<vector<int>>& nums, int n, vector<vector<int>>& dp){
        if(index==n)
            return 0;

        if(dp[index][prev+1] != -1) return dp[index][prev+1];

        int notTake = solve(index+1, prev, nums, n, dp);

        int take = 0;
        if(prev==-1 || (nums[index][0]>=nums[prev][0] && nums[index][1]>=nums[prev][1] && nums[index][2]>=nums[prev][2]))
            take = nums[index][2]+solve(index+1, index, nums, n, dp);

        return dp[index][prev+1] = max(take, notTake);
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        // Step 1: Sort all the dimensions for a particular cuboid
        for(auto& cuboid: cuboids){
            sort(cuboid.begin(), cuboid.end());
        }

        // Step 2: Sort all cuboids on the basis of w or l
        sort(cuboids.begin(), cuboids.end());

        // Step 3: Use Lis logic to find max height (condition - above cuboid
        // dimension should be less than below cuboid's dimension)
        int n = cuboids.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(0, -1, cuboids, n, dp);
    }
};