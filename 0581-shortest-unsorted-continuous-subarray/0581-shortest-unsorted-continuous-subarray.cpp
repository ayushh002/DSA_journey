class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = -1, right = -1;
        // Step 1: Find first break from left
        for(int i = 0; i<n-1; i++){
            if(nums[i]>nums[i+1]){
                left = i;
                break;
            }
        }
        // Check if array is already Sorted
        if(left==-1)
            return 0;
        // Step 2: Find first break from left
        for(int j = n-1; j>0; j--){
            if(nums[j]<nums[j-1]){
                right = j;
                break;
            }
        }
        // Step 3: Find min/max between [L..R] to expand 
        int subMin = INT_MAX, subMax = INT_MIN;
        for(int k = left; k<=right; k++){
            subMin = min(subMin, nums[k]);
            subMax = max(subMax, nums[k]);
        }
        // Step 4: Expand left subarray while nums[L-1] > min
        while(left>0 && nums[left-1]>subMin)
            left--;
        // Step 4: Expand left subarray while nums[L-1] > min
        while(right<n-1 && nums[right+1]<subMax)
            right++;

        return right-left+1;
    }
};