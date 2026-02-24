class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        int start = 0, end = 1;
        while(end<size){
            if(nums[start]!=nums[end]){
                start++;
                nums[start]=nums[end];
                end++;
            }
            else
                end++;
        }
        return start+1;
    }
};