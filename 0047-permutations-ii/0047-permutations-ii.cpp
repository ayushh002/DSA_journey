class Solution {
public:
    void findPermutations(vector<vector<int>>& ans, vector<int>& nums, int index) {

        if(index == nums.size()) {
            ans.push_back(nums);
            return;
        }
        vector<bool> included(21, 0);
        for(int i = index; i < nums.size(); i++) {
            if(!included[nums[i]+10]){
                included[nums[i]+10] = true;
                swap(nums[index], nums[i]);
                findPermutations(ans, nums, index+1);
                swap(nums[index], nums[i]);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        findPermutations(ans, nums, 0);
        return ans;
    }
};