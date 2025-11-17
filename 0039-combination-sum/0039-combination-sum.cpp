class Solution {
public:
    void findCombination(vector<vector<int>>& ans, vector<int>& candidates, vector<int>& temp, int index, int target){
        if(target==0){
            ans.push_back(temp);
            return;
        }

        if(index==candidates.size() || target<0) return;

        temp.push_back(candidates[index]);
        findCombination(ans, candidates, temp, index, target-candidates[index]);
        temp.pop_back();
        findCombination(ans, candidates, temp, index+1, target);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        findCombination(ans, candidates, temp, 0, target);
        return ans;
    }
};