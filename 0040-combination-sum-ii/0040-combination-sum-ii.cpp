class Solution {
public:
    void findCombination(vector<vector<int>>& ans, vector<int>& candidates, vector<int>& temp, int index, int target){
        if(target==0){
            ans.push_back(temp);
            return;
        }

        for(int i = index; i<candidates.size(); i++){
            if(i>index && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            temp.push_back(candidates[i]);
            findCombination(ans, candidates, temp, i+1, target-candidates[i]);
            temp.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        findCombination(ans, candidates, temp, 0, target);
        return ans;
    }
};