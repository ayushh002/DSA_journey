class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int size = nums.size();
        vector<int> ans;
        for(int i = 0 ; i < 2 * size; i++){
            ans.push_back(nums[i % size]);
        }
        return ans;
    }
};