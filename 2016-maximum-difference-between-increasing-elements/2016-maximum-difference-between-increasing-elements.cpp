class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int size = nums.size();
        int suffixMax = INT_MIN;
        int maxDiff = -1;
        for(int i = size-1; i>0; i--){
            suffixMax = max(suffixMax, nums[i]);
            if(nums[i-1]<suffixMax)
            maxDiff = max(maxDiff, suffixMax-nums[i-1]);
        }
        return maxDiff;
    }
};