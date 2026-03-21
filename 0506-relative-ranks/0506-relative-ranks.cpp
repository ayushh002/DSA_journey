class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        unordered_map<int, string> rank = {
            {1, "Gold Medal"},
            {2, "Silver Medal"},
            {3, "Bronze Medal"}
        };
        vector<string> ans(n);

        unordered_map<int, int> idxMap;
        for(int i = 0; i<n; i++)
            idxMap[score[i]] = i;
        
        priority_queue<int> pq;
        for(int x : score) pq.push(x);
        int count = 1;
        while(!pq.empty()){
            int top = pq.top();
            int index = idxMap[top];

            if(count<=3)
                ans[index] = rank[count];
            else
                ans[index] = to_string(count);
            
            count++;
            pq.pop();
        }
        return ans;
    }
};