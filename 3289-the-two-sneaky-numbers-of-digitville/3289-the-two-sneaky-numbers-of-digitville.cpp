class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i<n; i++){
            int index = nums[i]%n;

            nums[index] += n;

            if(nums[index]/n == 2)
                ans.push_back(index);
        }
        return ans;
    }
};