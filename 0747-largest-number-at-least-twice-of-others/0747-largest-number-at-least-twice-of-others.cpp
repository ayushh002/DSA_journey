class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max = -1, index;
        for(int i = 0; i<nums.size(); i++){
            if(max<nums[i]){
                index = i;
                max = nums[i];
            }
        }
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]*2>max && nums[i]!=max) 
                index = -1;
        }
        return index;
    }
};