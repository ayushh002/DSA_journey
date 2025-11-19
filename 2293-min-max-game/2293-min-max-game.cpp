class Solution {
public:
    int solve(int n, vector<int>& nums){
        if(n==1) return nums[0];
        vector<int> newNums;
        for(int i = 0; i<n/2; i++){
            if(i%2==0){
                newNums.push_back(min(nums[2 * i], nums[2 * i + 1]));
            }
            else{
                newNums.push_back(max(nums[2 * i], nums[2 * i + 1]));
            }
        }
        return solve(n/2, newNums);
    }
    int minMaxGame(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int ans = solve(nums.size(), nums);
        return ans;
    }
};