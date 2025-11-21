class Solution {
public:
    void subsequence(vector<int>& nums, int index, int size, vector<vector<int>>& ans, vector<int>& temp){
        if(index==size){
            ans.push_back(temp);
            return;
        }
        // case 1: not included
        int newIndex = index+1;
        while(newIndex<nums.size() && nums[index]==nums[newIndex])
            newIndex++;
        subsequence(nums, newIndex, size, ans, temp);
        // case 2: included
        temp.push_back(nums[index]);
        subsequence(nums, index+1, size, ans, temp);
        temp.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        subsequence(nums, 0, nums.size(), ans, temp);
        return ans;
    }
};