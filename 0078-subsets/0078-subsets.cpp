class Solution {
public:
    void subsequence(vector<int>& nums, int index, int size, vector<vector<int>>& ans, vector<int> temp){
        if(index==size){
            ans.push_back(temp);
            return;
        }
        // case 1: not included
        subsequence(nums, index+1, size, ans, temp);
        // case 2: included
        temp.push_back(nums[index]);
        subsequence(nums, index+1, size, ans, temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> temp;
        subsequence(nums, 0, nums.size(), ans, temp);
        return ans;
    }
};