class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int max = INT_MIN, prefix = 0;
        for(int i = 0; i<size; i++){
            prefix += nums[i];
            if(prefix>max)
                max = prefix;
            if(prefix<0) 
                prefix = 0;
        }
        return max;
    }
};