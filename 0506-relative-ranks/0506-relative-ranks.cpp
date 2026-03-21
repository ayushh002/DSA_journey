class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        
        // 1. Store (score, index)
        vector<pair<int, int>> vec;
        for(int i = 0; i<n; i++)
            vec.push_back({score[i], i});
        
        // Step 2: sort in descending order of score
        sort(vec.begin(), vec.end(), greater<pair<int, int>>());
        
        // 3. Prepare answer (assign ranks)
        vector<string> ans(n);
        for(int i = 0; i<n; i++){
            int idx = vec[i].second;

            if(i==0) ans[idx] = "Gold Medal";
            else if(i==1) ans[idx] = "Silver Medal";
            else if(i==2) ans[idx] = "Bronze Medal";
            else ans[idx] = to_string(i+1);
        }
        return ans;
    }
};