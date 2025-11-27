class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        int start = 0;
        int end = size-1;
        int index=size, mid;
        while(start<=end){
            mid = start + (end-start)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                start = mid+1;
            }
            else{
                index = mid;
                end = mid-1;
            }
        }
        return index;
    }
};