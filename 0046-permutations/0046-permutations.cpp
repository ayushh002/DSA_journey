class Solution {
public:
    void findPermutations(vector<vector<int>>& ans, vector<int>& nums, vector<bool>& visited, vector<int>& temp){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return; 
        }
        for(int i = 0; i<visited.size(); i++){
            if(!visited[i]){
                visited[i] = true;
                temp.push_back(nums[i]);
                findPermutations(ans, nums, visited, temp);
                visited[i] = false;
                temp.pop_back();
            }
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> visited(nums.size());
        findPermutations(ans, nums, visited, temp);
        return ans;
    }
};